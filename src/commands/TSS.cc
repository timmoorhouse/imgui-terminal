
#include <terminal/Terminal.hh>

namespace terminal {

// Thin Space Specification
// ECMA-48 8.3.157
bool
Terminal::TSS(uint32_t p)
{
	// no default

    log("TSS(%u)", p);

    //! @todo

    return false;
}

}
