
#include <terminal/Terminal.hh>

namespace terminal {

// Character Position Forward
// ECMA-48 8.3.59
bool
Terminal::HPR(uint32_t p)
{
    bool handled = _CUF(p);

    if (m_verbose || !handled)
    	log("HPR(%u)", p);

    return handled;
}

}
