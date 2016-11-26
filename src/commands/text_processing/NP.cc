
#include <terminal/Terminal.hh>

namespace terminal {

// Next Page
// ECMA-48 8.3.87
bool
Terminal::NP(uint32_t p)
{
    bool handled = _NP(p);

    if (m_verbose || !handled)
    	log("NP(%u)", p);

    return handled;
}

bool
Terminal::_NP(uint32_t p)
{
	if (p == 0)
		p = 1;

    //! @todo

    return false;
}

}
