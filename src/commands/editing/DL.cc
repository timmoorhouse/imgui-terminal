
#include <terminal/Terminal.hh>

namespace terminal {

// Delete Line
// ECMA-48 8.3.32
bool
Terminal::DL(uint32_t p)
{
    bool handled = _DL(p);

	if (m_verbose || !handled)
        log("DL(%u)", p);

    return handled;
}

bool
Terminal::_DL(uint32_t p)
{

    if (p == 0)
        p = 1;

    auto &b = s();

    // num lines from cursor to bottom, inclusive
    auto nlines = std::max(0U, b.height() - b.row() + 1);

    // num lines at bottom to fill with blanks
    auto nfill  = std::min(p, nlines);

    // num lines needing to be copied up
    auto ncopy  = nlines - nfill;

    if (ncopy > 0)
    	b.copy_rect(b.row() + nfill, 1,
    	            b.height(), b.width(),
    	            b.row(), 1);
    if (nfill > 0)
    	b.fill_rect(b.height() - nfill + 1, 1,
    	            b.height(), b.width());

    return true;
}

}
