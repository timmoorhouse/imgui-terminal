
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Select Character Protection Attribute
bool
Terminal::DECSCA(uint32_t p)
{
	bool handled = _DECSCA(p);

    if (m_verbose || !handled)
        log("DECSCA(%u)", p);

    return handled;
}

bool
Terminal::_DECSCA(uint32_t p)
{
	// default is 0

	bool prot;

	switch (p) {

	case 0:
	case 2:
		prot = false;
		break;

	case 1:
		prot = true;
		break;

	default:
		return false;

	}

    auto &b = s();
    uint64_t a = b.attributes();
    uint16_t m = miscAttributes(a);
    if (prot)
    	m |= ATTR_PROTECTED;
    else
    	m &= ~ATTR_PROTECTED;

    b.attributes(attribute(foreground(a),
                           background(a),
                           m));

    return true;
}

}
