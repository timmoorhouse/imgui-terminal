
#include <terminal/Terminal.hh>

namespace terminal {

// Graphic Character Combination
// ECMA-48 8.3.54
bool
Terminal::GCC(uint32_t p)
{
    bool handled = _GCC(p);

    if (m_verbose || !handled)
    	log("GCC(%u)", p);

    return handled;
}

bool
Terminal::_GCC(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
