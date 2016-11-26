
#include <terminal/Terminal.hh>

namespace terminal {

// Device Control Three
// ECMA-48 8.3.30
bool
Terminal::DC3()
{
    log("DC3");

    //! @todo
    //! @todo XOFF

    return false;
}

}
