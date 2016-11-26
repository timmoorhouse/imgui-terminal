
#include <terminal/Terminal.hh>

namespace terminal {

// Start Reversed String
// ECMA-48 8.3.137
bool
Terminal::SRS(uint32_t p)
{
    bool handled = _SRS(p);

    if (m_verbose || !handled)
    	log("SRS(%u)", p);

    return handled;
}

bool
Terminal::_SRS(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
