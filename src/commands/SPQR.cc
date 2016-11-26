
#include <terminal/Terminal.hh>

namespace terminal {

// Select Print Quality and Rapidity
// ECMA-48 8.3.134
bool
Terminal::SPQR(uint32_t p)
{
    bool handled = _SPQR(p);

    if (m_verbose || !handled)
    	log("SPQR(%u)", p);

    return handled;
}

bool
Terminal::_SPQR(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
