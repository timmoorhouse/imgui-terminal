
#include <terminal/Terminal.hh>
#include <algorithm>                    // min, max

namespace terminal {

// Line Position Absolute
// ECMA-48 8.3.158
bool
Terminal::VPA(uint32_t p)
{
    bool handled = _VPA(p);

    if (m_verbose || !handled)
        log("VPA(%u)", p);

    return handled;
}

bool
Terminal::_VPA(uint32_t p)
{
	if (p == 0)
		p = 1;

    auto &b = s();
    b.set_row(std::max(1U, std::min(p, b.height())));

    return true;
}

}
