
#include <terminal/Terminal.hh>
#include <algorithm>					// min, max

namespace terminal {

// Delete Character
// ECMA-48 8.3.26
bool
Terminal::DCH(uint32_t p)
{
    bool handled = _DCH(p);

	if (m_verbose || !handled)
    	log("DCH(%u)", p);

    return handled;
}

bool
Terminal::_DCH(uint32_t p)
{

    if (p == 0)
        p = 1;

    auto &b = s();

    // num chars from cursor to end of line, inclusive
    auto nchars = std::max(0U, b.width() - b.col() + 1);

    // num chars at end of line to fill with blanks
    auto nfill  = std::min(p, nchars);

    // num chars needing to be copied to the left
    auto ncopy  = nchars - nfill;

    if (ncopy > 0)
    	b.copy_rect(b.row(), b.col() + nfill,
    	            b.row(), b.width(),
    	            b.row(), b.col());
    if (nfill > 0)
    	b.fill_rect(b.row(), b.width() - nfill + 1,
    	            b.row(), b.width());

    return true;
}

}
