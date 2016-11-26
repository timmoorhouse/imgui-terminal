
#include <terminal/Terminal.hh>

namespace terminal {

// Graphic Size Modification
// ECMA-48 8.3.55
bool
Terminal::GSM(uint32_t p1, uint32_t p2)
{
    bool handled = _GSM(p1, p2);

    if (m_verbose || !handled)
    	log("GSM(%u,%u)", p1, p2);

    return handled;
}

bool
Terminal::_GSM(uint32_t p1, uint32_t p2)
{
	if (p1 == 0)
		p1 = 100;
	if (p2 == 0)
		p2 = 100;

    //! @todo

    return false;
}

}
