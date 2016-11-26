
#include <terminal/Terminal.hh>

namespace terminal {

// Assign Colour
bool
Terminal::DECAC(uint32_t p1, uint32_t p2, uint32_t p3)
{
    bool handled = _DECAC(p1, p2, p3);

    if (m_verbose || !handled)
        log("DECAC(%u,%u,%u)", p1, p2, p3);

    return handled;
}

bool
Terminal::_DECAC(uint32_t p1, uint32_t p2, uint32_t p3)
{
	//! @todo
	return false;
}

}
