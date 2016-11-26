
#include <terminal/Terminal.hh>

namespace terminal {

// Spacing Increment
// ECMA-48 8.3.132
bool
Terminal::SPI(uint32_t p1, uint32_t p2)
{
	// no default

    log("SPI(%u,%u)", p1, p2);

    //! @todo

    return false;
}

}
