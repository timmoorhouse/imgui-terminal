
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Double width, single height line
bool
Terminal::DECDWL()
{
	bool handled = _DECDWL();

    if (m_verbose || !handled)
        log("DECDWL");

    return handled;
}

bool
Terminal::_DECDWL()
{
	if (!dec_mode(dec_mode_t::DECLRMM)) {

    	auto &b = s();

    	uint64_t a = b.attributes();
    	uint16_t m = miscAttributes(a);

    	m &= ~(ATTR_DBL_HIGH_TOP | ATTR_DBL_HIGH_BOTTOM);
    	m |= ATTR_DBL_WIDE;

    	b.attributes(attribute(foreground(a),
    	                       background(a),
    	                       m));

	}

	return false;
}

}
