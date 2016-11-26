
#include <terminal/Terminal.hh>

namespace terminal {

// Erase Character
// ECMA-48 8.3.38
bool
Terminal::ECH(uint32_t p)
{
    bool handled = _ECH(p);

    if (m_verbose || !handled)
    	log("ECH(%u)", p);

    return handled;
}

bool
Terminal::_ECH(uint32_t p)
{

	if (p == 0)
		p = 1;

    auto &b = s();

    // num chars from cursor to end of line, inclusive
    auto nchars = std::max(0U, b.width() - b.col() + 1);

    // num chars at cursor to fill with blanks
    auto nfill  = std::min(p, nchars);

    if (nfill > 0)
    	b.fill_rect(b.row(), b.col(),
    	            b.row(), b.col() + nfill - 1);

    return true;

}

}
