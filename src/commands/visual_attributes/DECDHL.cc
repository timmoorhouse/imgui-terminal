
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Double width, double height line
bool
Terminal::DECDHL(bool top)
{
	bool handled = _DECDHL(top);

    if (m_verbose || !handled)
        log("DECDHL(%u)", top);

    return handled;
}

bool
Terminal::_DECDHL(bool top)
{
	if (!dec_mode(dec_mode_t::DECLRMM)) {

	    auto &b = s();

	    uint64_t a = b.attributes();
	    uint16_t m = miscAttributes(a);

	    m &= ~(ATTR_DBL_HIGH_TOP | ATTR_DBL_HIGH_BOTTOM);
	    m |= ATTR_DBL_WIDE;
	    m |= top ? ATTR_DBL_HIGH_TOP : ATTR_DBL_HIGH_BOTTOM;

	    b.attributes(attribute(foreground(a),
	                           background(a),
	                           m));

	}

	return false;
}

}
