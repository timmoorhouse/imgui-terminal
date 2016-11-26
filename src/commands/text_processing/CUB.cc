
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Left
// ECMA-48 8.3.18
bool
Terminal::CUB(uint32_t p)
{
    bool handled = _CUB(p);

    if (m_verbose || !handled)
        log("CUB(%u)", p);

    return handled;
}

bool
Terminal::_CUB(uint32_t p)
{
    if (p == 0)
        p = 1;

    auto &b = s();

    //! @todo check character path
    if (b.col() > p)
        b.set_col(b.col() - p);
    else
        b.set_col(1);

    return true;
}

}
