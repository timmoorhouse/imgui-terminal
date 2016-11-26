
#include <terminal/Terminal.hh>

namespace terminal {

// Justify
// ECMA-48 8.3.73
bool
Terminal::JFY(uint32_t p)
{
    bool handled = _JFY(p);

    if (m_verbose || !handled)
    	log("JFY(%u)", p);

    return handled;
}

bool
Terminal::_JFY(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
