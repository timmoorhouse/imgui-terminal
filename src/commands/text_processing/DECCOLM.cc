
#include <terminal/Terminal.hh>

namespace terminal {

//
bool
Terminal::DECCOLM(bool set)
{
    bool handled = true;

    auto &b = s();

    if ((set && (b.width(true) != 132)) ||
        (!set && (b.width(true) != 80))) {

        resize(set ? 132 : 80, b.height());
        _DECSLRM(0,0);
        _DECSTBM(0,0);

    }

	if (m_verbose || !handled)
    	log("DECCOLM(%u)", set);

#if 0
    std::cout << "DECCOLM:"
              << " set=" << set
              << " w=" << b.width(true)
              << " rm=" << b.m_margin.m_right
              << " h=" << b.height(true)
              << " bm=" << b.m_margin.m_bottom
              << std::endl;
#endif

    return handled;
}

}
