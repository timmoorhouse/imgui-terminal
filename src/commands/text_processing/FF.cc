
#include <terminal/Terminal.hh>

namespace terminal {

// Form Feed
// ECMA-48 8.3.51
bool
Terminal::FF()
{
    //! @todo DEC treats as LF

    bool handled = _LF();

    if (m_verbose || !handled)
        log("FF");

    return handled;
}

}
