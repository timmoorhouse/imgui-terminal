
#include <terminal/Terminal.hh>

namespace terminal {

// Terminal ID
bool
Terminal::DECID()
{
    bool handled = _DA(0);

    if (m_verbose || !handled)
        log("DECID");

    return handled;
}

}
