
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Select Graphic Rendition
// ECMA-48 8.3.117
bool
Terminal::SGR(uint32_t p)
{
    bool handled = _SGR(p);

    if (m_verbose || !handled)
        log("SGR(%u)", p);

    return handled;
}

bool
Terminal::_SGR(uint32_t p)
{
    // default is 0

    auto &b = s();

    uint64_t a = b.attributes();
    uint32_t fg = foreground(a);
    uint32_t bg = background(a);
    uint16_t m = miscAttributes(a);

    //! @todo
    switch (p) {

    case 0: // normal
        fg = s_colormap[NORMAL_WHITE];
        bg = s_colormap[NORMAL_BLACK];
        m = 0; //! @todo should this clear protected?
        break;

    case 1: // bold
        m |= ATTR_BOLD;
        break;

    case 4: // underscore
        m |= ATTR_UNDERLINE;
        break;

    case 5: // blink
        m |= ATTR_BLINK;
        break;

    case 7: // reverse
        m |= ATTR_REVERSE;
        break;

    case 8: // hidden
        m |= ATTR_HIDDEN;
        break;

    //case 10: //! @todo see DEC
    //case 11: //! @todo see DEC
    //case 12: //! @todo see DEC

    case 22: // DEC-specific
        m &= ~ATTR_BOLD;
        break;

    case 24: // DEC-specific
        m &= ~ATTR_UNDERLINE;
        break;

    case 25: // DEC-specific
        m &= ~ATTR_BLINK;
        break;

    case 27: // DEC-specific
        m &= ~ATTR_REVERSE;
        break;

    case 28: // DEC-specific
        m &= ~ATTR_HIDDEN;
        break;

    case 30: // foreground
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
        fg = s_colormap[p - 30 + ((m & ATTR_BOLD) ? 8 : 0)];
        break;

    case 39: // default foreground
        fg = s_colormap[NORMAL_WHITE];
        break;

    case 40: // background
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
        bg = s_colormap[p - 40 + ((m & ATTR_BOLD) ? 8 : 0)];
        break;

    case 49: // default background
        bg = s_colormap[NORMAL_BLACK];
        break;

    default:
        return false;

    }

    b.attributes(attribute(fg, bg, m));
    return true;
}

}
