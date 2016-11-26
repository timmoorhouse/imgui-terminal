
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::DECRST(uint32_t p)
{
    bool handled = _DECSET(p, false);

    if (m_verbose || !handled)
        log("DECRST(%u)", p);

    return handled;
}

}
