
#include <terminal/Terminal.hh>

namespace terminal {

// Cancel
// ECMA-48 8.3.6
bool
Terminal::CAN()
{
    //if (m_verbose)
    log("CAN");

    // noop
    //! @todo DEC cancels any in-progress escape sequence

    return false;
}

}
