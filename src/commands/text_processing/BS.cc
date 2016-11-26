
#include <terminal/Terminal.hh>

namespace terminal {

// Backspace
// ECMA-48 8.3.5
bool
Terminal::BS()
{
    bool handled = _BS();

    if (m_verbose || !handled)
        log("BS");

    return handled;
}

bool
Terminal::_BS()
{
    auto &b = s();

    //! @todo check simd
    if (b.col() > 1)
        b.set_col(b.col() - 1);

    return true;
}

}
