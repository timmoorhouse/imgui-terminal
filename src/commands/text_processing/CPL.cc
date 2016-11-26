
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Preceding Line
// ECMA-48 8.3.13
bool
Terminal::CPL(uint32_t p)
{
    bool handled = _CPL(p);

    if (m_verbose || !handled)
    	log("CPL(%u)", p);

    return handled;
}

bool
Terminal::_CPL(uint32_t p)
{
	if (p == 0)
		p = 1;

	_CR();

    auto &b = s();
    if (b.row() > p)
        b.set_row(b.row() - p);
    else {
        b.set_row(1);
        //_SD(p - (b.height() - b.row()));
    }

    return true;
}

}
