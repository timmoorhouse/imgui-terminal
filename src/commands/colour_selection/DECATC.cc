
#include <terminal/Terminal.hh>

namespace terminal {

// Alternate Text Colour
bool
Terminal::DECATC(uint32_t p1, uint32_t p2, uint32_t p3)
{
    bool handled = _DECATC(p1, p2, p3);

    if (m_verbose || !handled)
        log("DECATC(%u,%u,%u)", p1, p2, p3);

    return handled;
}

bool
Terminal::_DECATC(uint32_t p1, uint32_t p2, uint32_t p3)
{
	//! @todo
	return false;
}

}
