
#include <terminal/Terminal.hh>
#include <algorithm>					// min, max

namespace terminal {

bool
Terminal::DECSLRM(uint32_t pl, uint32_t pr)
{
	bool handled = _DECSLRM(pl, pr);

	if (m_verbose || !handled)
		log("DECSTBM(%u,%u)", pl, pr);

	return handled;
}

bool
Terminal::_DECSLRM(uint32_t pl, uint32_t pr)
{
#if 0
	if (!dec_mode(dec_mode_t::DECLRMM))
		return true;
#endif

	auto &b = s();

	if (pl == 0)
		pl = 1;
	if (pr == 0)
		pr = b.width(true);

	uint32_t min_width = 2;

	b.m_margin.m_left  = std::min(std::max(1U, pl),
	                              b.width(true) - min_width + 1);
	b.m_margin.m_right = std::min(std::max(b.m_margin.m_left + min_width - 1, pr),
	                              b.width(true));

	_CUP(1,1);

    return true;
}

}
