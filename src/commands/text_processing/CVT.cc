
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Line Tabulation
// ECMA-48 8.3.23
bool
Terminal::CVT(uint32_t p)
{
    bool handled = _CVT(p);

    if (m_verbose || !handled)
    	log("CVT(%u)", p);

    return handled;
}

bool
Terminal::_CVT(uint32_t p)
{
	if (p == 0)
		p = 1;

    //! @todo

    return false;
}

}
