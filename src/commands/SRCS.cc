
#include <terminal/Terminal.hh>

namespace terminal {

// Set Reduced Character Separation
// ECMA-48 8.3.136
bool
Terminal::SRCS(uint32_t p)
{
    bool handled = _SRCS(p);

    if (m_verbose || !handled)
    	log("SRCS(%u)", p);

    return handled;
}

bool
Terminal::_SRCS(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
