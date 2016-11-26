
#include <terminal/Terminal.hh>

namespace terminal {

// End of Transmission Block
// ECMA-48 8.3.49
bool
Terminal::ETB()
{
    if (m_verbose)
        log("ETB");

    // noop

    return true;
}

}
