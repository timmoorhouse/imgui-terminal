
#include <terminal/Terminal.hh>

namespace terminal {

// Select Size Unit
// ECMA-48 8.3.139
bool
Terminal::SSU(uint32_t p)
{
    bool handled = _SSU(p);

    if (m_verbose || !handled)
    	log("SSU(%u)", p);

    return handled;
}

bool
Terminal::_SSU(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
