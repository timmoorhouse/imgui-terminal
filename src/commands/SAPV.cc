
#include <terminal/Terminal.hh>

namespace terminal {

// Select Alternative Presentation Variants
// ECMA-48 8.3.108
bool
Terminal::SAPV(uint32_t p)
{
    bool handled = _SAPV(p);

    if (m_verbose || !handled)
    	log("SAPV(%u)", p);

    return handled;
}

bool
Terminal::_SAPV(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
