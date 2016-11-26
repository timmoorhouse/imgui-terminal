
#include <terminal/Terminal.hh>
#include <algorithm>                    // min, max

namespace terminal {

// Cursor Next Line
// ECMA-48 8.3.12
bool
Terminal::CNL(uint32_t p)
{
    bool handled = _CNL(p);

    if (m_verbose || !handled)
    	log("CNL(%u)", p);

    return handled;
}

bool
Terminal::_CNL(uint32_t p)
{
	if (p == 0)
		p = 1;

	_CR();

    auto &b = s();
    if ((b.height() - b.row()) >= p)
        b.set_row(b.row() + p);
    else {
        b.set_row(b.height());
        _SU(p - (b.height() - b.row()));
    }

    return true;
}

}
