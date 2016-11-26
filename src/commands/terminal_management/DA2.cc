
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::DA2(uint32_t p)
{
    bool handled = _DA2(p);

    if (m_verbose || !handled)
    	log("DA2(%u)", p);

    return handled;
}

bool
Terminal::_DA2(uint32_t p)
{
	// default is 0

    return false;
}

}
