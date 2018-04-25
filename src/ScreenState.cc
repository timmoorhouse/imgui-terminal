
#include <terminal/ScreenState.hh>
#include <terminal/attribute.hh>
#include <algorithm>
#include <iostream> //! @todo
#include <cassert>

namespace terminal {

ScreenState::ScreenState()
{
    resize(80, 24);

    m_margin.m_top    = 1;
    m_margin.m_left   = 1;
    m_margin.m_bottom = m_height;
    m_margin.m_right  = m_width;
    m_wrap_pending    = false;
}

uint32_t
ScreenState::width(bool overall) const
{
#if 0
    if (!dec_mode(dec_mode_t::DECLRMM))
        overall = false;
#endif
    return overall ? m_width : m_margin.m_right - m_margin.m_left + 1;
}

uint32_t
ScreenState::height(bool overall) const
{
    return overall ? m_height : m_margin.m_bottom - m_margin.m_top + 1;
}

uint32_t
ScreenState::row(bool overall) const
{
    return overall ? m_cursor.m_r : m_cursor.m_r - (m_margin.m_top - 1);
}

void
ScreenState::set_row(uint32_t r, bool overall)
{
    m_wrap_pending = false;
    m_cursor.m_r = overall ? r : r + (m_margin.m_top - 1);
}

uint32_t
ScreenState::col(bool overall) const
{
    return overall ? m_cursor.m_c : m_cursor.m_c - (m_margin.m_left - 1);
}

void
ScreenState::set_col(uint32_t c, bool overall)
{
    m_wrap_pending = false;
    m_cursor.m_c = overall ? c : c + (m_margin.m_left - 1);
}

uint32_t
ScreenState::index(uint32_t r, uint32_t c, bool overall) const
{
    if (overall)
        return (r-1)*m_width + (c-1);
    else
        return (r-1+m_margin.m_top-1)*m_width + (c-1+m_margin.m_left-1);
}

uint32_t
ScreenState::row_of(uint32_t index, bool overall) const
{
    //! @todo handle overall
    return (index / m_width) + 1;
}

uint32_t
ScreenState::col_of(uint32_t index, bool overall) const
{
    //! @todo handle overall
    return (index % m_width) + 1;
}

uint8_t *
ScreenState::bufp(uint32_t r, uint32_t c, bool overall)
{
    // note: this can be one past the end column when finding
    // the end iterator of a range to draw
    return m_screen.data() + index(r, c, overall);
}

uint8_t &
ScreenState::buf(uint32_t r, uint32_t c, bool overall)
{
    return m_screen[index(r, c, overall)];
}

uint64_t &
ScreenState::attr(uint32_t r, uint32_t c, bool overall)
{
    return m_attributes[index(r, c, overall)];
}

uint8_t &
ScreenState::tab(uint32_t c, bool overall)
{
    //! @todo handle overall
    return m_tab[c-1];
}

uint64_t
ScreenState::attributes() const
{
    return m_cursor.m_attributes; // attribute(m_cursor.m_foreground, m_cursor.m_background, 0);
}

void
ScreenState::attributes(uint64_t a)
{
    m_cursor.m_attributes = a;
}

void
ScreenState::save_cursor()
{
    m_saved_cursor = m_cursor;
}

void
ScreenState::restore_cursor()
{
    m_cursor = m_saved_cursor;
}

void
ScreenState::resize(uint32_t width, uint32_t height)
{
    m_width  = width;
    m_height = height;

    m_cursor.m_r = std::min(m_cursor.m_r, height);
    m_cursor.m_c = std::min(m_cursor.m_c, width);


    //! @todo preserve contents of maintained region?

    m_screen.resize(m_height*m_width);
    m_attributes.resize(m_height*m_width);
    m_tab.resize(m_width);

    fill_rect(1, 1, m_height, m_width, ' ', true);
}

void
ScreenState::fill_rect(uint32_t t, uint32_t l, uint32_t b, uint32_t r,
                       uint8_t fill, bool overall)
{
#if 1
    fill_rect_if(t, l, b, r,
                 [](uint32_t, uint32_t, uint8_t, uint64_t) {
                    return true;
                 },
                 fill, overall);
#else
    uint32_t r_min = std::max(t, 1U);
    uint32_t r_max = std::min(b, height(overall));
    uint32_t c_min = std::max(l, 1U);
    uint32_t c_max = std::min(r, width(overall));
    uint64_t att   = m_cursor.m_attributes;
    for (uint32_t row=r_min; row <= r_max; row++) {
        for (uint32_t col=c_min; col <= c_max; col++) {
            buf(row, col, overall) = fill;
            attr(row, col, overall) = att;
        }
    }
#endif
}

void
ScreenState::fill_rect_if(uint32_t t, uint32_t l, uint32_t b, uint32_t r,
                          predicate_t p,
                          uint8_t fill, bool overall)
{
    uint32_t r_min = std::max(t, 1U);
    uint32_t r_max = std::min(b, height(overall));
    uint32_t c_min = std::max(l, 1U);
    uint32_t c_max = std::min(r, width(overall));
    uint64_t att   = m_cursor.m_attributes;
    for (uint32_t row=r_min; row <= r_max; row++) {
        for (uint32_t col=c_min; col <= c_max; col++) {
            auto &b = buf(row, col, overall);
            auto &a = attr(row, col, overall);
            if (p(row, col, b, a)) {
                b = fill;
                a = att;
            }
        }
    }
}

void
ScreenState::copy_rect(uint32_t st, uint32_t sl, uint32_t sb, uint32_t sr,
                       uint32_t dt, uint32_t dl, bool overall)
{
    uint32_t db = dt + (sb - st);
    uint32_t dr = dl + (sr - sl);

    uint32_t r_off_max = std::min(std::min(sb, height()) - st,
                                  std::min(db, height()) - dt);
    uint32_t c_off_max = std::min(std::min(sr, width()) - sl,
                                  std::min(dr, width()) - dl);


    if (index(st, sl, overall) > index(dt, dl, overall)) {

        // copy forwards
        for (int32_t r_off = 0; r_off <= r_off_max; r_off++) {
            for (int32_t c_off = 0; c_off <= c_off_max; c_off++) {
                buf(dt+r_off, dl+c_off, overall) = buf(st+r_off, sl+c_off, overall);
                attr(dt+r_off, dl+c_off, overall) = attr(st+r_off, sl+c_off, overall);
            }
        }

    } else {

        // copy backwards
        for (int32_t r_off = r_off_max; r_off >= 0; r_off--) {
            for (int32_t c_off = c_off_max; c_off >= 0; c_off--) {
                buf(dt+r_off, dl+c_off, overall) = buf(st+r_off, sl+c_off, overall);
                attr(dt+r_off, dl+c_off, overall) = attr(st+r_off, sl+c_off, overall);
            }
        }

    }
}

}
