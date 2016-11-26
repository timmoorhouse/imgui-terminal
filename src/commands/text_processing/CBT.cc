
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Backward Tabulation
// ECMA-48 8.3.7
bool
Terminal::CBT(uint32_t p)
{
    bool handled = _CBT(p);

    if (m_verbose || !handled)
    	log("CBT(%u)", p);

    return handled;
}

bool
Terminal::_CBT(uint32_t p)
{
	if (p == 0)
		p = 1;

    auto &b = s();

    while (p > 0) {
        if (b.col() <= 1)
            break;
        b.set_col(b.col() - 1);
        if (b.tab(b.col()))
            p--;
    }

    return true;

}

}
