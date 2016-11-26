
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Copy Rectangular Area
bool
Terminal::DECCRA(uint32_t ts, uint32_t ls, uint32_t bs, uint32_t rs, uint32_t ps,
                 uint32_t td, uint32_t ld, uint32_t pd)
{
	bool handled = _DECCRA(ts, ls, bs, rs, ps, td, ld, pd);

    if (m_verbose || !handled)
        log("DECCRA(%u,%u,%u,%u,%u,%u,%u,%u)", ts, ls, bs, rs, ps, td, ld, pd);

    return handled;
}

bool
Terminal::_DECCRA(uint32_t ts, uint32_t ls, uint32_t bs, uint32_t rs, uint32_t ps,
                  uint32_t td, uint32_t ld, uint32_t pd)
{
	//! @todo
	auto &b = s();

	if (ts == 0)
		ts = 1;
	if (ls == 0)
		ls = 1;
	if (bs == 0)
		bs = b.height();
	if (rs == 0)
		rs = b.width();
	if (ps == 0)
		ps = 1;
	if (td == 0)
		td = 1;
	if (ld == 0)
		ld = 1;
	if (pd == 0)
		pd = 1;

	b.copy_rect(ts, ls, bs, rs, td, ld); //! @todo ps, pd

	return true;
}

}
