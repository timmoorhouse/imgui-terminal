
#include <terminal/Terminal.hh>

namespace terminal {

// Line Feed
// ECMA-48 8.3.74
bool
Terminal::LF()
{
    bool handled = _LF();

    if (m_verbose || !handled)
        log("LF");

    return handled;
}

bool
Terminal::_LF()
{
    auto &b = s();

    if (b.row() < b.height())
        b.set_row(b.row() + 1);
    else
        _SU(1);

    return true;
}

}
