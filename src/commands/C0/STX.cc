
#include <terminal/Terminal.hh>

namespace terminal {

// Start of Text
// ECMA-48 8.3.146
bool
Terminal::STX()
{
    if (m_verbose)
        log("STX");

    // noop

    return true;
}

}
