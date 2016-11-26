
#include <terminal/Terminal.hh>

namespace terminal {

// Parallel Texts
// ECMA-48 8.3.99
bool
Terminal::PTX(uint32_t p)
{
    bool handled = _PTX(p);

    if (m_verbose || !handled)
    	log("PTX(%u)", p);

    return handled;
}

bool
Terminal::_PTX(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
