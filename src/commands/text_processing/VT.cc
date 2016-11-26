
#include <terminal/Terminal.hh>

namespace terminal {

// Line Tabulation
// ECMA-48 8.3.161
bool
Terminal::VT()
{
    bool handled = _LF();

    if (m_verbose || !handled)
        log("VT");

    //! @todo DEC treats as LF

    return handled;
}

}
