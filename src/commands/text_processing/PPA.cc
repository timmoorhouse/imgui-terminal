
#include <terminal/Terminal.hh>

namespace terminal {

// Page Position Absolute
// ECMA-48 8.3.96
bool
Terminal::PPA(uint32_t p)
{
    bool handled = _PPA(p);

    if (m_verbose || !handled)
    	log("PPA(%u)", p);

    return handled;
}

bool
Terminal::_PPA(uint32_t p)
{
	if (p == 0)
		p = 1;

    //! @todo

    return false;
}

}
