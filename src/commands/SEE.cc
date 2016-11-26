
#include <terminal/Terminal.hh>

namespace terminal {

// Select Editing Extent
// ECMA-48 8.3.115
bool
Terminal::SEE(uint32_t p)
{
    bool handled = _SEE(p);

    if (m_verbose || !handled)
    	log("SEE(%u)", p);

    return handled;
}

bool
Terminal::_SEE(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
