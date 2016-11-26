
#include <terminal/Terminal.hh>

namespace terminal {

// Session Page Memory Allocation
bool
Terminal::DECSPMA(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4)
{
    bool handled = _DECSPMA(p1, p2, p3, p4);

    if (m_verbose || !handled)
    	log("DECSPMA(%u,%u,%u,%u)", p1, p2, p3, p4);

    return handled;
}

bool
Terminal::_DECSPMA(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4)
{
	// on zero, leave unchanged

    //! @todo

    return false;
}

}
