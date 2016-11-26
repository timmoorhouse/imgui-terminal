
#include <terminal/Terminal.hh>

namespace terminal {

// Insert Character
// ECMA-48 8.3.64
bool
Terminal::ICH(uint32_t p)
{
    bool handled = _ICH(p);

	if (m_verbose || !handled)
    	log("ICH(%u)", p);

    return handled;
}

bool
Terminal::_ICH(uint32_t p)
{
	if (p == 0)
		p = 1;

    auto &b = s();

    // num chars from cursor to end of line, inclusive
    auto nchars = std::max(0U, b.width() - b.col() + 1);

    // num chars at cursor to fill with blanks
    auto nfill  = std::min(p, nchars);

    // num chars needing to be copied to the right
    auto ncopy  = nchars - nfill;

    if (ncopy > 0)
    	b.copy_rect(b.row(), b.col(),
    	            b.row(), b.col() + ncopy - 1,
    	            b.row(), b.col() + nfill);
    if (nfill > 0)
    	b.fill_rect(b.row(), b.col(),
    	            b.row(), b.col() + nfill - 1);

    return true;
}

}
