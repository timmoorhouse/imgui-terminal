
#include <terminal/Terminal.hh>

namespace terminal {

//! @todo delete this?  it's the response, not the request

// Active Position Report
// ECMA-48 8.3.14
bool
Terminal::CPR(uint32_t p1, uint32_t p2)
{
    bool handled = _CPR(p1, p2);

    if (m_verbose || !handled)
    	log("CPR(%u,%u)", p1, p2);

    return handled;
}

bool
Terminal::_CPR(uint32_t p1, uint32_t p2)
{
	if (p1 == 0)
		p1 = 1;
	if (p2 == 0)
		p2 = 1;

    //! @todo

    return false;
}

}
