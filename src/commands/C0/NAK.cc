
#include <terminal/Terminal.hh>

namespace terminal {

// Negative Acknowledge
// ECMA-48 8.3.84
bool
Terminal::NAK()
{
    if (m_verbose)
        log("NAK");

    // noop

    return true;
}

}
