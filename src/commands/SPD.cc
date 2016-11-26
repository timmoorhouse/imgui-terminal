
#include <terminal/Terminal.hh>

namespace terminal {

// Select Presentation Directions
// ECMA-48 8.3.130
bool
Terminal::SPD(uint32_t p1, uint32_t p2)
{
    bool handled = _SPD(p1, p2);

    if (m_verbose || !handled)
    	log("SPD(%u,%u)", p1, p2);

    return handled;
}

bool
Terminal::_SPD(uint32_t p1, uint32_t p2)
{
	// default is 0, 0

    //! @todo

    return false;
}

}
