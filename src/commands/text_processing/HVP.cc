
#include <terminal/Terminal.hh>

namespace terminal {

// Character and Line Position
// ECMA-48 8.3.63
bool
Terminal::HVP(uint32_t r, uint32_t c)
{
    bool handled = _CUP(r, c);

    if (m_verbose || !handled)
        log("HVP(%u,%u)", r, c);

    return handled;
}

}
