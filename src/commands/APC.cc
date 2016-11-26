
#include <terminal/Terminal.hh>
#include <algorithm>                    // min, max

namespace terminal {

// Application Program Command
// ECMA-48 8.3.2
bool
Terminal::APC(const std::string &p)
{
    if (m_verbose)
        log("APC");

    // noop

    // APC : <lots> ST                DECEKBD extended keyboard report

    return false;
}

}
