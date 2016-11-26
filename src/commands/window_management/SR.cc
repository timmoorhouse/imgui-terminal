
#include <terminal/Terminal.hh>

namespace terminal {

// Scroll Right
// ECMA-48 8.3.135
bool
Terminal::SR(uint32_t p)
{
    bool handled = _SR(p);

    if (m_verbose || !handled)
    	log("SR(%u)", p);

    return handled;
}

bool
Terminal::_SR(uint32_t p)
{
	if (p == 0)
		p = 1;

    auto &b = s();

    if (p < b.width())
        b.copy_rect(1, 1,
                    b.height(), b.width()-p,
                    1, 1+p);

    b.fill_rect(1, 1, b.height(), std::min(p, b.width()));

    return true;
}

}
