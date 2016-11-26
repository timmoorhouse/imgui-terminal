
#include <terminal/Terminal.hh>
#include <algorithm>                    // min, max

namespace terminal {

// Cursor Character Absolute
// ECMA-48 8.3.9
bool
Terminal::CHA(uint32_t p)
{
    bool handled = _CHA(p);

    if (m_verbose || !handled)
        log("CHA(%u)", p);

    return handled;
}

bool
Terminal::_CHA(uint32_t p)
{
	if (p == 0)
		p = 1;

	auto &b = s();
	b.set_col(std::max(1U, std::min(p, b.width())));

    return true;
}

}
