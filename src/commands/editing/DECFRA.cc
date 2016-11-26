
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Fill Rectangular Area
bool
Terminal::DECFRA(uint32_t pch, uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr)
{
	bool handled = _DECFRA(pch, pt, pl, pb, pr);

    if (m_verbose || !handled)
        log("DECFRA(%u,%u,%u,%u,%u)", pch, pt, pl, pb, pr);

    return handled;
}

bool
Terminal::_DECFRA(uint32_t pch, uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr)
{

	if (((pch >= 32) && (pch <= 126)) ||
	    ((pch >= 160) && (pch <= 255))) {

		auto &b = s();

		if (pt == 0)
			pt = 1;
		if (pl == 0)
			pl = 1;
		if (pb == 0)
			pb = b.height();
		if (pr == 0)
			pr = b.width();

		//! @todo attributes!
		b.fill_rect(pt, pl, pb, pr, pch);

	}

	return true;
}

}
