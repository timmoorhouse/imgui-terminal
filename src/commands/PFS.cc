
#include <terminal/Terminal.hh>

namespace terminal {

// Page Format Selection
// ECMA-48 8.3.91
bool
Terminal::PFS(uint32_t p)
{
    bool handled = _PFS(p);

    if (m_verbose || !handled)
    	log("PFS(%u)", p);

    return handled;
}

bool
Terminal::_PFS(uint32_t p)
{
	// default is 0

    //! @todo

    return false;
}

}
