
#include <terminal/Terminal.hh>

namespace terminal {

// Select Implicit Movement Direction
// ECMA-48 8.3.120
bool
Terminal::SIMD(uint32_t p)
{
    bool handled = _SIMD(p);

    if (m_verbose || !handled)
    	log("SIMD(%u)", p);

    return handled;
}

bool
Terminal::_SIMD(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
