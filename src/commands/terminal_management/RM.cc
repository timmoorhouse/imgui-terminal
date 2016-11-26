
#include <terminal/Terminal.hh>
#include <algorithm>                    // min, max

namespace terminal {

// Reset Mode
// ECMA-48 8.3.106
bool
Terminal::RM(uint32_t p)
{
    bool handled = _SM(p, false);

    if (m_verbose || !handled)
        log("RM(%u)", p);

    return handled;
}

}
