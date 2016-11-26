
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::DECTST(uint32_t p)
{
	bool handled = _DECTST(p);

	if (m_verbose || !handled)
		log("DECTST(%u)", p);

	return handled;
}

bool
Terminal::_DECTST(uint32_t p)
{
	//! @todo default????

	//! @todo

    return false;
}

}
