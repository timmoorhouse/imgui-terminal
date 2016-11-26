
#include <terminal/Terminal.hh>

namespace terminal {

// Reverse Line Feed
// ECMA-48 8.3.104
bool
Terminal::RI()
{
    bool handled = _RI();

    if (m_verbose || !handled)
        log("RI");

    return handled;
}

bool
Terminal::_RI()
{
    auto &b = s();

    if (b.row() > 1)
        b.set_row(b.row() - 1);
    else
        _SD(1);

    return true;
}

}
