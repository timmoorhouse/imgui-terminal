
#include <terminal/Terminal.hh>

namespace terminal {

// Next Line
// ECMA-48 8.3.86
bool
Terminal::NEL()
{
    bool handled = _CNL(1);

    if (m_verbose || !handled)
        log("NEL");

    return handled;
}

}
