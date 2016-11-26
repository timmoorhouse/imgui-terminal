
#include <terminal/Terminal.hh>

namespace terminal {

// Presentation Expand or Contract
// ECMA-48 8.3.90
bool
Terminal::PEC(uint32_t p)
{
    bool handled = _PEC(p);

    if (m_verbose || !handled)
    	log("PEC(%u)", p);

    return handled;
}

bool
Terminal::_PEC(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
