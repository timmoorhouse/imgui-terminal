
#include <terminal/Terminal.hh>

namespace terminal {

// Dimension Text Area
// ECMA-48 8.3.36
bool
Terminal::DTA(uint32_t p1, uint32_t p2)
{
	// no defaults

    log("DTA(%u,%u)", p1, p2);

    //! @todo

    return false;
}

}
