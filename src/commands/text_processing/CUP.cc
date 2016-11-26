
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Position
// ECMA-48 8.3.21
bool
Terminal::CUP(uint32_t r, uint32_t c)
{
    bool handled = _CUP(r, c);

    if (m_verbose || !handled)
        log("CUP(%u,%u)", r, c);

    return handled;
}

bool
Terminal::_CUP(uint32_t r, uint32_t c)
{
	if (r == 0)
		r = 1;
	if (c == 0)
		c = 1;

    _CHA(c);
    _VPA(r);

    return true;
}

}
