
#include <terminal/Terminal.hh>

namespace terminal {

// Character Tabulation
// ECMA-48 8.3.60
bool
Terminal::HT()
{
    bool handled = _CHT(1);

    if (m_verbose || !handled)
        log("HT");

    return handled;
}

}
