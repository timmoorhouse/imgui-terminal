
#include <terminal/Terminal.hh>

namespace terminal {

// Device Attributes
// ECMA-48 8.3.24
bool
Terminal::DA(uint32_t p)
{
    bool handled = _DA(p);

    if (m_verbose || !handled)
        log("DA(%u)", p);

    return handled;
}

bool
Terminal::_DA(uint32_t p)
{
    // default is 0

    //! @todo
    switch (p) {

    case 0:
        //! @todo
        output(0x9B); // CSI
        output('?');
        {
            bool first = true;
            uint32_t attr[] = {
                //65, // VT500 family // ... stuck on DCS " p  ???
                1,  // 132 columns
                // 2, // printer port
                // 6,  // selective erase (implied by 65)
                // 7, // soft character set (DRCS)
                // 8, // user-defined keys (UDKs) (implied by 65)
                // 9, // national replacement character sets (NRCS)
                // 12, // serbo-croatian (SCS)
                // 15, // technical character set (implied by 65)
                // 18, // windowing capability
                // 19, // sessions
                21, // horizontal scrolling
                22  // colour
                // 23, // greek
                // 24, // turkish
                // 42, // ISO latin-2
                // 44, // PCTerm
                // 45, // soft key mapping
                // 46, // ASCII terminal emulation
            };
            for (auto ps : attr) {
                if (!first)
                    output(';');
                output("%u", ps);
                first = false;
            }
        }
        output('c');
        return true;

    }

    return false;
}

}
