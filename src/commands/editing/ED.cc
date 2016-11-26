
#include <terminal/Terminal.hh>

namespace terminal {

// Erase in Page
// ECMA-48 8.3.39
bool
Terminal::ED(uint32_t p)
{
    bool handled = _ED(p);

    if (m_verbose || !handled)
        log("ED(%u)", p);

    return handled;
}

bool
Terminal::_ED(uint32_t p)
{
    // default is 0

    auto &b = s();

    //! @todo check dcsm
    switch (p) {

    case 0:
        // erase to end of page
        _EL(p); // cursor to end of line
        b.fill_rect(b.row()+1, 1, b.height(), b.width());
        return true;

    case 1:
        // erase from start of page
        b.fill_rect(1, 1, b.row()-1, b.width());
        _EL(p); // start of line to cursor
        return true;

    case 2:
        // erase entire page
        b.fill_rect(1, 1, b.height(), b.width());
        return true;

    }

    return false;
}

}
