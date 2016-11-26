
#include <terminal/Terminal.hh>

namespace terminal {

// Character Position Backward
// ECMA-48 8.3.58
bool
Terminal::HPB(uint32_t p)
{
    bool handled = _CUB(p);

    if (m_verbose || !handled)
    	log("HPB(%u)", p);

    return handled;
}

}
