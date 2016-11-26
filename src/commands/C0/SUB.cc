
#include <terminal/Terminal.hh>

namespace terminal {

// Substitute
// ECMA-48 8.3.148
bool
Terminal::SUB()
{
    //if (m_verbose)
    log("SUB");

    // noop
    //! @todo DEC cancels any in-progress sequence, displays ? in place

    return false;
}

}
