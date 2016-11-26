
#include <terminal/Terminal.hh>

namespace terminal {

// Scroll Down
// ECMA-48 8.3.113
bool
Terminal::SD(uint32_t p)
{
    bool handled = _SD(p);

    if (m_verbose || !handled)
    	log("SD(%u)", p);

    return handled;
}

bool
Terminal::_SD(uint32_t p)
{
	if (p == 0)
		p = 1;

    auto &b = s();

    if (p < b.height())
        b.copy_rect(1, 1,
                    b.height()-p, b.width(),
                    p+1, 1);
    b.fill_rect(1, 1, std::min(p, b.height()), b.width());

    return false;
}

}
