
#include <terminal/Terminal.hh>

namespace terminal {

// Function Key
// ECMA-48 8.3.52
bool
Terminal::FNK(uint32_t p)
{
	// no default

    log("FNK(%u)", p);

    //! @todo

    return false;
}

}
