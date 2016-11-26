
#include <terminal/Terminal.hh>

namespace terminal {

// Set Additional Character Separation
// ECMA-48 8.3.107
bool
Terminal::SACS(uint32_t p)
{
    bool handled = _SACS(p);

    if (m_verbose || !handled)
    	log("SACS(%u)", p);

    return handled;
}

bool
Terminal::_SACS(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
