
#include <terminal/Terminal.hh>

namespace terminal {

// Select Character Orientation
// ECMA-48 8.3.110
bool
Terminal::SCO(uint32_t p)
{
    bool handled = _SCO(p);

    if (m_verbose || !handled)
    	log("SCO(%u)", p);

    return handled;
}

bool
Terminal::_SCO(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
