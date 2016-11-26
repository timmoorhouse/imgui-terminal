
#include <terminal/Terminal.hh>

namespace terminal {

// Page Position Forward
// ECMA-48 8.3.98
bool
Terminal::PPR(uint32_t p)
{
    bool handled = _PPR(p);

    if (m_verbose || !handled)
    	log("PPR(%u)", p);

    return handled;
}

bool
Terminal::_PPR(uint32_t p)
{
	if (p == 0)
		p = 1;

    //! @todo

    return false;
}

}
