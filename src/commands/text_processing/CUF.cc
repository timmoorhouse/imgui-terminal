
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Right
// ECMA-48 8.3.20
bool
Terminal::CUF(uint32_t p)
{
    bool handled = _CUF(p);

    if (m_verbose || !handled)
        log("CUF(%u)", p);

    return handled;
}

bool
Terminal::_CUF(uint32_t p)
{
    if (p == 0)
        p = 1;

    auto &b = s();

    //! @todo check character path
    if ((b.width() - b.col()) >= p)
        b.set_col(b.col() + p);
    else
        b.set_col(b.width());

    return true;
}

}
