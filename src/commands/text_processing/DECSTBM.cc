
#include <terminal/Terminal.hh>
#include <algorithm>					// min, max

namespace terminal {

bool
Terminal::DECSTBM(uint32_t pt, uint32_t pb)
{
	bool handled = _DECSTBM(pt, pb);

	if (m_verbose || !handled)
		log("DECSTBM(%u,%u)", pt, pb);

	return handled;
}

bool
Terminal::_DECSTBM(uint32_t pt, uint32_t pb)
{
	auto &b = s();

	if (pt == 0)
		pt = 1;
	if (pb == 0)
		pb = b.height(true);

	uint32_t min_height = 1;

	b.m_margin.m_top    = std::min(std::max(1U, pt),
	                               b.height(true) - min_height + 1);
	b.m_margin.m_bottom = std::min(std::max(b.m_margin.m_top + min_height - 1, pb),
	                               b.height(true));

	_CUP(1,1);

    return true;
}

}
