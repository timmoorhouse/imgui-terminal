
#include <terminal/Terminal.hh>

namespace terminal {

// Character Position Absolute
// ECMA-48 8.3.57
bool
Terminal::HPA(uint32_t p)
{
    bool handled = _CHA(p);

    if (m_verbose || !handled)
        log("HPA(%u)", p);

    return handled;
}

}
