
#include <terminal/Terminal.hh>

namespace terminal {

// Interrupt
// ECMA-48 8.3.68
bool
Terminal::INT()
{
    log("INT");

    //! @todo

    return false;
}

}
