
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Selective Erase in Line
bool
Terminal::DECSEL(uint32_t p)
{
    bool handled = _DECSEL(p);

    if (m_verbose || !handled)
        log("DECSEL(%u)", p);

    return handled;
}

bool
Terminal::_DECSEL(uint32_t p)
{
    // default is 0

    auto &b = s();

    switch (p) {

    case 0:
        // erase to end of line
        return _DECSERA(b.row(), b.col(), b.row(), b.width());

    case 1:
        // erase from start of line
        return _DECSERA(b.row(), 1, b.row(), b.col());

    case 2:
        // erase entire line
        return _DECSERA(b.row(), 1, b.row(), b.width());

    }

    return false;
}

}
