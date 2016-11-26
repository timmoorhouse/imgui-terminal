
#include <terminal/Terminal.hh>

namespace terminal {

// Identify Device Control String
// ECMA-48 8.3.65
bool
Terminal::IDCS(uint32_t p)
{
	// no default

    log("IDCS(%u)", p);

    //! @todo

    return false;
}

}
