
#include <terminal/Terminal.hh>

namespace terminal {

// Information Separator Three (GS - Group Separator)
// ECMA-48 8.3.71
bool
Terminal::IS3()
{
    if (m_verbose)
        log("IS3");

    // noop

    return true;
}

}
