
#include <terminal/Terminal.hh>

namespace terminal {

// Character Tabulation Set
// ECMA-48 8.3.62
bool
Terminal::HTS()
{
	bool handled = _HTS();

    if (m_verbose || !handled)
        log("HTS");

    return handled;
}

bool
Terminal::_HTS()
{
    auto &b = s();

    if ((b.col() >= 1) && (b.col() <= b.width()))
    	b.tab(b.col()) = 1;

    return true;
}

}
