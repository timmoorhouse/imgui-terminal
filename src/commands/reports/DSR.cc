
#include <terminal/Terminal.hh>

namespace terminal {

// Device Status Report
// ECMA-48 8.3.35
bool
Terminal::DSR(uint32_t p)
{
    bool handled = _DSR(p);

    if (m_verbose || !handled)
        log("DSR(%u)", p);

    return handled;
}

bool
Terminal::_DSR(uint32_t p)
{
    // default is 0

    bool handled = false;

    auto &b = s();

    switch (p) {

    case 0:
        // ready, no malfunction
        handled = true;
        break;

    case 1:
        // busy, another DSR must be requested later
        handled = true;
        break;

    case 2:
        // busy, another DSR will be sent later
        handled = true;
        break;

    case 3:
        // some malfunction detected, another DSR must be requested later
        handled = true;
        break;

    case 4:
        // some malfunction detected, another DSR will be sent later
        handled = true;
        break;

    case 5:
        // a DSR is requested
        output("%c%un", 0x9B, 0); // OK (3=malfunction)
        handled = true;
        break;

    case 6:
        // CPR cursor position report
        output("%c%u;%uR", 0x9B, b.row(), b.col());
        handled = true;
        break;
    }

    //! ? 6                 DECXCPR extended cursor position report
    //! ? 15                printer port report
    //! ? 25                user defined keys report
    //! ? 26                keyboard report
    //! ? 62                macro space report
    //! ? 63 ; Pid          memory checksum report
    //! ? 75             data integrity report

    return handled;
}

}
