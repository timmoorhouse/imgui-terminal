
#include <terminal/Terminal.hh>

namespace terminal {

// Carriage Return
// ECMA-48 8.3.15
bool
Terminal::CR()
{
    bool handled = _CR();

    if (m_verbose || !handled)
        log("CR");

    return handled;
}

bool
Terminal::_CR()
{
    auto &b = s();

    //! @todo check SIMD, etc
    b.set_col(1);

    return true;
}

}
