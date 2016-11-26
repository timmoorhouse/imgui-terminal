
#include <terminal/Terminal.hh>

namespace terminal {

// End of Text
// ECMA-48 8.3.50
bool
Terminal::ETX()
{
    if (m_verbose)
        log("ETX");

    // noop

    return true;
}

}
