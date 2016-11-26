
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Erase Rectangular Area
bool
Terminal::DECERA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr)
{
	bool handled = _DECERA(pt, pl, pb, pr);

    if (m_verbose || !handled)
        log("DECERA(%u,%u,%u,%u)", pt, pl, pb, pr);

    return handled;
}

bool
Terminal::_DECERA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr)
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

	//! @todo should erase visual attributes, but not line attributes!
	b.fill_rect(pt, pl, pb, pr);

	return true;
}

}
