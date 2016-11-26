
#include <terminal/Terminal.hh>

namespace terminal {

// Update Session
bool
Terminal::DECUS(uint32_t p)
{
    bool handled = _DECUS(p);

    if (m_verbose || !handled)
    	log("DECUS(%u)", p);

    return handled;
}

bool
Terminal::_DECUS(uint32_t p)
{
	if (p == 0)
		p = 2;

    //! @todo

    return false;
}

}
