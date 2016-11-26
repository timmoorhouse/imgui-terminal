
#include <terminal/Terminal.hh>

namespace terminal {

// Scroll Left
// ECMA-48 8.3.121
bool
Terminal::SL(uint32_t p)
{
    bool handled = _SL(p);

    if (m_verbose || !handled)
    	log("SL(%u)", p);

    return handled;
}

bool
Terminal::_SL(uint32_t p)
{
	if (p == 0)
		p = 1;

    auto &b = s();

    if (p < b.height())
        b.copy_rect(1, 1+p,
                    b.height(), b.width(),
                    1, 1);
    b.fill_rect(1, std::max(1U,b.width()-p+1), b.height(), b.width());

    return true;
}

}
