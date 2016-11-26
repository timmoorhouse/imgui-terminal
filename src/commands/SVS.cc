
#include <terminal/Terminal.hh>

namespace terminal {

// Select Line Spacing
// ECMA-48 8.3.149
bool
Terminal::SVS(uint32_t p)
{
    bool handled = _SVS(p);

    if (m_verbose || !handled)
    	log("SVS(%u)", p);

    return handled;
}

bool
Terminal::_SVS(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
