
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Forward Tabulation
// ECMA-48 8.3.10
bool
Terminal::CHT(uint32_t p)
{
    bool handled = _CHT(p);

    if (m_verbose || !handled)
    	log("CHT(%u)", p);

    return handled;
}

bool
Terminal::_CHT(uint32_t p)
{
	if (p == 0)
		p = 1;

    auto &b = s();

    while (p > 0) {
        if (b.col() >= b.width())
            break;
        b.set_col(b.col() + 1);
        if (b.tab(b.col()))
            p--;
    }

    return true;
}

}
