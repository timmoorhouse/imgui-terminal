
#include <terminal/Terminal.hh>

namespace terminal {

// Select Character Spacing
// ECMA-48 8.3.118
bool
Terminal::SHS(uint32_t p)
{
    bool handled = _SHS(p);

    if (m_verbose || !handled)
    	log("SHS(%u)", p);

    return handled;
}

bool
Terminal::_SHS(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
