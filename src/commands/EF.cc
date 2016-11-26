
#include <terminal/Terminal.hh>

namespace terminal {

// Erase in Field
// ECMA-48 8.3.40
bool
Terminal::EF(uint32_t p)
{
    bool handled = _EF(p);

    if (m_verbose || !handled)
    	log("EF(%u)", p);

    return handled;
}

bool
Terminal::_EF(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
