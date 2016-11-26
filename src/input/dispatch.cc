
#include <terminal/Terminal.hh>
#include "ascii.hh"

namespace terminal {

bool
Terminal::p_dispatch(uint8_t c)
{
    bool handled = true;

    //! @todo table dispatch?

    switch (c) {

    case ::NUL:
        return NUL();

    case ::SOH:
        return SOH();

    case ::STX:
        return STX();

    case ::ETX:
        return ETX();

    case ::EOT:
        return EOT();

    case ::ENQ:
        return ENQ();

    case ::ACK:
        return ACK();

    case ::BEL:
        return BEL();

    case ::BS:
        return BS();

    case ::HT:
        return HT();

    case ::LF:
        return LF();

    case ::VT:
        return VT();

    case ::FF:
        return FF();

    case ::CR:
        return CR();

    case ::SO:
        return LS1();

    case ::SI:
        return LS0();

    case ::DLE:
        return DLE();

    case ::DC1:
        return DC1();

    case ::DC2:
        return DC2();

    case ::DC3:
        return DC3();

    case ::DC4:
        return DC4();

    case ::NAK:
        return NAK();

    case ::SYN:
        return SYN();

    case ::ETB:
        return ETB();

    case ::CAN:
        return CAN();

    case ::EM:
        return EM();

    case ::SUB:
        return SUB();

    case ::ESC:
        return false;

    case ::FS:
        return IS4();

    case ::GS:
        return IS3();

    case ::RS:
        return IS2();

    case ::US:
        return IS1();

    // 0x20 Space
    // !
    // "
    // #
    // $
    // %
    // &
    // '
    // (
    // )
    // *
    // +
    // ,
    // -
    // .
    // /
    // 0 .. 9
    // :
    // ;
    // <
    // =
    // >
    // ?
    // @
    // A .. Z
    // [
    // \
    // ]
    // ^
    // _
    // `
    // a .. z
    // {
    // |
    // }
    // ~

    case ::DEL: // 0x7F
        return false; //! @todo DEC ignores unless mapped by GL

    // 0x80..0x81

    case 0x82:
        return BPH();

    case 0x83:
        return NBH();

    case 0x84:
        return IND();

    case 0x85:
        return NEL();

    case 0x86:
        return SSA();

    case 0x87:
        return ESA();

    case 0x88:
        return HTS();

    case 0x89:
        return HTJ();

    case 0x8A:
        return VTS();

    case 0x8B:
        return PLD();

    case 0x8C:
        return PLU();

    case 0x8D:
        return RI();

    case 0x8E:
        return SS2();

    case 0x8F:
        return SS3();

    case 0x90:
#if 0
        switch (c1) {

        case -1:
             m_parse.m_state = ParseState::state_t::COMMAND_STRING;
             m_parse.m_reset = false;
             break;

        default:
            DCS(m_parse.m_parm_s);
        }
#endif
        return false;

    case 0x91:
        return PU1();

    case 0x92:
        return PU2();

    case 0x93:
        return STS();

    case 0x94:
        return CCH();

    case 0x95:
        return MW();

    case 0x96:
        return SPA();

    case 0x97:
        return EPA();

    case 0x98:
#if 0
        switch (c1) {

        case -1:
             m_parse.m_state = ParseState::state_t::COMMAND_STRING;
             m_parse.m_reset = false;
             break;

        default:
            SOS(m_parse.m_parm_s);
        }
#endif
        return false;

    // 0x99

    case 0x9A:
        //! @todo SCI or DECID
        return SCI();

    case 0x9B: // CSI
        return false;

    case 0x9C:
        //ST();
        return false;

    case 0x9D:
#if 0
        switch (c1) {

        case -1:
             m_parse.m_state = ParseState::state_t::COMMAND_STRING;
             m_parse.m_reset = false;
             break;

        default:
            OSC(m_parse.m_parm_s);
        }
#endif
        return false;

    case 0x9E:
#if 0
         switch (c1) {

        case -1:
             m_parse.m_state = ParseState::state_t::COMMAND_STRING;
             m_parse.m_reset = false;
             break;

        default:
            PM(m_parse.m_parm_s);
        }
#endif
        return false;

    case 0x9F:
#if 0
        switch (c1) {

        case -1:
             m_parse.m_state = ParseState::state_t::COMMAND_STRING;
             m_parse.m_reset = false;
             break;

        default:
            APC(m_parse.m_parm_s);
        }
#endif
        return false;

    // 0xA0..0xFF

    default:
        return p_print(c);

    }

}

}
