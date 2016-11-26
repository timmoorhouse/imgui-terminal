
#include <terminal/Terminal.hh>

namespace terminal {

// Sheet Eject and Feed
// ECMA-48 8.3.116
bool
Terminal::SEF(uint32_t p1, uint32_t p2)
{
    bool handled = _SEF(p1, p2);

    if (m_verbose || !handled)
    	log("SEF(%u,%u)", p1, p2);

    return handled;
}

bool
Terminal::_SEF(uint32_t p1, uint32_t p2)
{
	// default is 0, 0

    //! @todo

    return false;
}

}
