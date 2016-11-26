
#include <terminal/Terminal.hh>
#include <algorithm>                    // min, max

namespace terminal {

// Scroll Up
// ECMA-48 8.3.147
bool
Terminal::SU(uint32_t p)
{
    bool handled = _SU(p);

    if (m_verbose || !handled)
        log("SU(%u)", p);

    return handled;
}

bool
Terminal::_SU(uint32_t p)
{
    if (p == 0)
        p = 1;

    auto &b = s();

    if (p < b.height())
        b.copy_rect(p+1, 1,
                    b.height(), b.width(),
                    1, 1);
    b.fill_rect(std::max(1U,b.height()-p+1), 1, b.height(), b.width());

    return true;
}

}
