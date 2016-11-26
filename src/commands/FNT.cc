
#include <terminal/Terminal.hh>

namespace terminal {

// Font Selection
// ECMA-48 8.3.53
bool
Terminal::FNT(uint32_t p1, uint32_t p2)
{
    bool handled = _FNT(p1, p2);

    if (m_verbose || !handled)
    	log("FNT(%u,%u)", p1, p2);

    return handled;
}

bool
Terminal::_FNT(uint32_t p1, uint32_t p2)
{
	// default is 0, 0

    //! @todo

    return false;
}

}
