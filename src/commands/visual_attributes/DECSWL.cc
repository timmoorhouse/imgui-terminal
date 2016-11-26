
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Single width, single height line
bool
Terminal::DECSWL()
{
	bool handled = _DECSWL();

    if (m_verbose || !handled)
        log("DECSWL");

    return handled;
}

bool
Terminal::_DECSWL()
{
    auto &b = s();

    uint64_t a = b.attributes();
    uint16_t m = miscAttributes(a);

    m &= ~(ATTR_DBL_WIDE | ATTR_DBL_HIGH_TOP | ATTR_DBL_HIGH_BOTTOM);

    b.attributes(attribute(foreground(a),
                           background(a),
                           m));

	return false;
}

}
