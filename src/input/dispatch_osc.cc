
#include <terminal/Terminal.hh>
#include <regex>

namespace terminal {

// Operating System Command
// ECMA-48 8.3.89
bool
Terminal::p_dispatch_osc()
{
    log("OSC[%s]", m_parse.m_parm_s.c_str());

    //! @todo OSC 2 D..D ST       - DECSIN set icon name (D..D is L;name)
    //! @todo OSC 2 D..D ST       - DECSWT set window title (D..D is 1;name)

    std::regex bits_regex("(.);(.*)");
    std::smatch bits_match;

    if (std::regex_match(m_parse.m_parm_s, bits_match, bits_regex)) {
        auto p = bits_match[0].str();
    }

    //! @todo handle xterm style parameter strings in the form Ps ; Pt
#if 0
    std::string pt(reinterpret_cast<char*>(&m_parse.m_seq[eps+1]), ept-eps);
    std::cout << "GOT TEXT PARM [" << pt << "]" << std::endl;

    switch (m_parse.m_parm[0]) {

    case 0:
        m_icon_name = pt;
        // fallthrough ...
    case 2:
        title(pt);
        break;

    case 1:
        m_icon_name = pt;
        break;

    case 46:
        m_log_file = pt;
        break;

    case 50:
        m_font_name = pt;
        break;
    }
#endif

    return false;
}

}
