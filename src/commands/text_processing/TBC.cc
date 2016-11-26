
#include <terminal/Terminal.hh>

namespace terminal {

// Tabulation Clear
// ECMA-48 8.3.154
bool
Terminal::TBC(uint32_t p)
{
    bool handled = _TBC(p);

    if (m_verbose || !handled)
        log("TBC(%u)", p);

    return handled;
}

bool
Terminal::_TBC(uint32_t p)
{
    // default is 0

    // DEC supports 0, 3 only
    // ECMA-48 defines 0 to 5

    auto &b = s();

    switch (p) {

    case 0:
    	if ((b.col() >= 1) && (b.col() <= b.width()))
    		b.tab(b.col()) = 0;
    	return true;

    case 1:
        //! @todo clear line tab stop on active line
        return false;

    case 2:
        //! @todo clear all charater tab stops on active line
        return false;

    case 3:
    	for (uint32_t c=1; c <= b.width(); c++)
            b.tab(c) = 0;
    	return true;

    case 4:
        //! @todo clear all line tab stops
        return false;

    case 5:
        //! @todo clear all tab stops
        return false;

    }

    return false;
}

}
