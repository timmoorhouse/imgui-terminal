
#include <terminal/Terminal.hh>

namespace terminal {

// Quad
// ECMA-48 8.3.102
bool
Terminal::QUAD(uint32_t p)
{
    bool handled = _QUAD(p);

    if (m_verbose || !handled)
    	log("QUAD(%u)", p);

    return handled;
}

bool
Terminal::_QUAD(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
