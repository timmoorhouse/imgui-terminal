
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::DA3(uint32_t p)
{
    bool handled = _DA3(p);

    if (m_verbose || !handled)
    	log("DA3(%u)", p);

    return handled;
}

bool
Terminal::_DA3(uint32_t p)
{
	// default is 0

    return false;
}

}
