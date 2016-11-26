
#include <terminal/Terminal.hh>

namespace terminal {

// Page Position Backward
// ECMA-48 8.3.97
bool
Terminal::PPB(uint32_t p)
{
    bool handled = _PPB(p);

    if (m_verbose || !handled)
    	log("PPB(%u)", p);

    return handled;
}

bool
Terminal::_PPB(uint32_t p)
{
	if (p == 0)
		p = 1;

    //! @todo

    return false;
}

}
