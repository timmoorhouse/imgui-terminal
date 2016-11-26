
#include <terminal/Terminal.hh>

namespace terminal {

// Define Area Qualification
// ECMA-48 8.3.25
bool
Terminal::DAQ(uint32_t p)
{
    bool handled = _DAQ(p);

    if (m_verbose || !handled)
    	log("DAQ(%u)", p);

    return handled;
}

bool
Terminal::_DAQ(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
