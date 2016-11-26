
#include <terminal/Terminal.hh>

namespace terminal {

// Information Separator One (US - Unit Separator)
// ECMA-48 8.3.69
bool
Terminal::IS1()
{
    if (m_verbose)
        log("IS1");

    // noop

    return true;
}

}
