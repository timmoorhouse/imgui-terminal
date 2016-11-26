
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Tabulation Control
// ECMA-48 8.3.17
bool
Terminal::CTC(uint32_t p)
{
    bool handled = _CTC(p);

    if (m_verbose || !handled)
    	log("CTC(%u)", p);

    return handled;
}

bool
Terminal::_CTC(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
