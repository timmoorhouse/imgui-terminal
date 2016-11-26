
#include <terminal/Terminal.hh>

namespace terminal {

// Preceding Page
// ECMA-48 8.3.95
bool
Terminal::PP(uint32_t p)
{
    bool handled = _PP(p);

    if (m_verbose || !handled)
    	log("PP(%u)", p);

    return handled;
}

bool
Terminal::_PP(uint32_t p)
{
	if (p == 0)
		p = 1;

    //! @todo

    return false;
}

}
