
#include <terminal/Terminal.hh>
#include <algorithm>                    // min, max

namespace terminal {

// Repeat
// ECMA-48 8.3.103
bool
Terminal::REP(uint32_t p)
{
    bool handled = _REP(p);

    if (m_verbose || !handled)
    	log("REP");

    return handled;
}

bool
Terminal::_REP(uint32_t p)
{
	if (p == 0)
		p = 1;

    //! @todo

    return false;
}

}
