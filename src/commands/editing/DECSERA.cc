
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

static bool
unprotected(uint32_t, uint32_t, uint8_t, uint64_t a)
{
    return !(miscAttributes(a) & ATTR_PROTECTED);
}

// Selective Erase Rectangular Area
bool
Terminal::DECSERA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr)
{
	bool handled = _DECSERA(pt, pl, pb, pr);

    if (m_verbose || !handled)
        log("DECSERA(%u,%u,%u,%u)", pt, pl, pb, pr);

    return handled;
}

bool
Terminal::_DECSERA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr)
{
	auto &b = s();

	if (pt == 0)
		pt = 1;
	if (pl == 0)
		pl = 1;
	if (pb == 0)
		pb = b.height();
	if (pr == 0)
		pr = b.width();

	//! @todo should not change attributes!
    b.fill_rect_if(pt, pl, pb, pr, unprotected);

	return true;
}

}
