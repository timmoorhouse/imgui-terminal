
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Selective Erase in Display
bool
Terminal::DECSED(uint32_t p)
{
    bool handled = _DECSED(p);

    if (m_verbose || !handled)
        log("DECSED(%u)", p);

    return handled;
}

bool
Terminal::_DECSED(uint32_t p)
{
    // default is 0

    auto &b = s();

    switch (p) {

    case 0:
        // erase to end of page
        _DECSEL(p); // cursor to end of line
        _DECSERA(b.row()+1, 1, b.height(), b.width());
        return true;

    case 1:
        // erase from start of page
        _DECSERA(1, 1, b.row()-1, b.width());
        _DECSEL(p); // start of line to cursor
        return true;

    case 2:
        // erase entire page
        _DECSERA(1, 1, b.height(), b.width());
        return true;

    }

    return false;
}

}
