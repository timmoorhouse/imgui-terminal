
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Down
// ECMA-48 8.3.19
bool
Terminal::CUD(uint32_t p)
{
    bool handled = _CUD(p);

    if (m_verbose || !handled)
        log("CUD(%u)", p);

    return handled;
}

bool
Terminal::_CUD(uint32_t p)
{
    if (p == 0)
        p = 1;

    auto &b = s();

    //! @todo check character path
    if ((b.height() - b.row()) >= p)
        b.set_row(b.row() + p);
    else
        b.set_row(b.height());

    return true;
}

}
