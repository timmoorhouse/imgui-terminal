
#include <terminal/Terminal.hh>

namespace terminal {

// Erase in Line
// ECMA-48 8.3.41
bool
Terminal::EL(uint32_t p)
{
    bool handled = _EL(p);

    if (m_verbose || !handled)
        log("EL(%u)", p);

    return handled;
}

bool
Terminal::_EL(uint32_t p)
{
    // default is 0

    auto &b = s();

    //! @todo check dcsm
    switch (p) {

    case 0:
        // erase to end of line
        b.fill_rect(b.row(), b.col(), b.row(), b.width());
        return true;

    case 1:
        // erase from start of line
        b.fill_rect(b.row(), 1, b.row(), b.col());
        return true;

    case 2:
        // erase entire line
        b.fill_rect(b.row(), 1, b.row(), b.width());
        return true;

    }

    return false;
}

}
