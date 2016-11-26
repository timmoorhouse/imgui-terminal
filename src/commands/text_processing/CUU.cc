
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Up
// ECMA-48 8.3.22
bool
Terminal::CUU(uint32_t p)
{
    bool handled = _CUU(p);

    if (m_verbose || !handled)
        log("CUU(%u)", p);

    return handled;
}

bool
Terminal::_CUU(uint32_t p)
{
    if (p == 0)
        p = 1;

    auto &b = s();

    //! @todo check character path
    if (b.row() > p)
        b.set_row(b.row() - p);
    else
        b.set_row(1);

    return true;
}

}
