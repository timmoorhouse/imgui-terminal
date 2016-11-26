
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Change Attributes in Rectangular Area
bool
Terminal::DECCARA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr, uint32_t ps)
{
	bool handled = _DECCARA(pt, pl, pb, pr, ps);

    if (m_verbose || !handled)
        log("DECCARA(%u,%u,%u,%u,%u)", pt, pl, pb, pr, ps);

    return handled;
}

bool
Terminal::_DECCARA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr, uint32_t ps)
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

	//! @todo

	return false;
}

}
