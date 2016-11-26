
#include <terminal/Terminal.hh>

namespace terminal {

// Tabulation Centred on Character
// ECMA-48 8.3.155
bool
Terminal::TCC(uint32_t p1, uint32_t p2)
{
    bool handled = _TCC(p1, p2);

    if (m_verbose || !handled)
    	log("TCC(%u,%u)", p1, p2);

    return handled;
}

bool
Terminal::_TCC(uint32_t p1, uint32_t p2)
{
	// no default for p1

	if (p2 == 0)
		p2 = 32; // space

    //! @todo

    return false;
}

}
