
#include <terminal/Terminal.hh>

namespace terminal {

// Insert Line
// ECMA-48 8.3.67
bool
Terminal::IL(uint32_t p)
{
    bool handled = _IL(p);

	if (m_verbose || !handled)
        log("IL(%u)", p);

    return handled;
}

bool
Terminal::_IL(uint32_t p)
{
    if (p == 0)
        p = 1;

    auto &b = s();

    //! @todo check scrolling region!

    // num lines from cursor to bottom, inclusive
    auto nlines = std::max(0U, b.height() - b.row() + 1);

    // num lines to fill with blanks
    auto nfill  = std::min(p, nlines);

    // num lines needing to be copied up
    auto ncopy  = nlines - nfill;

    if (ncopy > 0)
    	b.copy_rect(b.row(), 1,
    	            b.row() + ncopy - 1, b.width(),
    	            b.height() - ncopy + 1, 1);

    if (nfill > 0)
    	b.fill_rect(b.row(), 1,
    	            b.row() + nfill - 1, b.width());

    return true;
}

}
