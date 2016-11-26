
#include <terminal/Terminal.hh>
#include "ascii.hh"

namespace terminal {

/*
    // ESC ( C
    // ESC ) C
    // ESC * C
    // ESC + C

    // ESC ] Ps ; Pt BEL            Tektronix
    // ESC `                        Tektronix
    // ESC a                        Tektronix
    // ESC b                        Tektronix
    // ESC c                        Tektronix
    // ESC d                        Tektronix
    // ESC h                        Tektronix
    // ESC i                        Tektronix
    // ESC j                        Tektronix
    // ESC k                        Tektronix
    // ESC l                        Tektronix
    // ESC p                        Tektronix
    // ESC q                        Tektronix
    // ESC r                        Tektronix
    // ESC s                        Tektronix
    // ESC t                        Tektronix
*/

bool
Terminal::p_dispatch_esc(uint8_t c)
{

    switch (c) {

    // 0x00
    // 0x01
    // 0x02

    case 0x03:
        //! @todo Tektronix - switch to VT100
        break;

    // 0x04

    case 0x05:
        //! @todo Tektronix - return terminal status
        break;

    // 0x06
    // 0x07
    // 0x08
    // 0x09
    // 0x0A
    // 0x0B

    case 0x0C:
        //! @todo Tektronix - PAGE (clear screen)
        break;

    // 0x0D

    case 0x0E:
        //! @todo Tektronix - begin 4015 APL mode (xterm ignores)
        break;

    case 0x0F:
        //! @todo Tektronix - end 4015 APL mode (xterm ignores)
        break;

    // 0x10
    // 0x11
    // 0x12
    // 0x13
    // 0x14
    // 0x15
    // 0x16

    case 0x17:
        //! @todo Tektronix - COPY
        break;

    case 0x18:
        //! @todo Tektronix - bypass condition
        break;

    // 0x19

    case 0x1A:
        //! @todo Tektronix - GIN mode
        break;

    // 0x1B

    case 0x1C:
        //! @todo Tektronix - special point lot mode
        break;

    // 0x1D

    // 0x1E

    // 0x1F

    // 0x20 .. 0x2F are intermediate

    // ( - designate character set G0?
    // ) - designate character set G1?
    // * - designate character set G2?
    // + - designate character set G3?

    // 0x30 0

    case 0x31: // 1
        if (m_parse.m_int == ")")
            return DDD1();

        if (m_parse.m_int == "(")
            return DDD3();

        break;

    //case 0x32: // 2

    case 0x33: // 3
        if (m_parse.m_int == "#")
            return DECDHL(true); // double width, double height line, top half
        break;

    case 0x34: // 4
        if (m_parse.m_int == "#")
            return DECDHL(false); // double width, double height line, bottom half
        break;

    case 0x35: // 5
        if (m_parse.m_int == "#")
            return DECSWL(); // single width, single height line
        break;

    case 0x36: // 6

        if (m_parse.m_int == "#")
            return DECDWL(); // double width, single height line

        if (m_parse.m_int == "")
            return DECBI();

        break;

    case 0x37: // 7
        if (m_parse.m_int == "")
            return DECSC(); // save cursor and attributes
        break;

    case 0x38: // 8
        //! @todo Tektronix - select large character set

        if (m_parse.m_int == "#")
            return DECALN();

        if (m_parse.m_int == "")
            return DECRC(); // restore cursor and attributes

        break;

    case 0x39: // 9
        //! @todo Tektronix - select #2 character set
        if (m_parse.m_int == "")
            return DECFI();
        break;

    case 0x3A: // :
        //! @todo Tektronix - select #3 character set
        break;

    case 0x3B: // ;
        //! @todo Tektronix - select small character set
        break;

    // 0x3C: // <
        // ESC <    - exit DECANM

    case 0x3D: // =
        if (m_parse.m_int == "")
            return DECKPAM(); // application keypad mode
        break;

    case 0x3E: // >
        if (m_parse.m_int == "")
            return DECKPNM(); // numeric keypad mode
        break;

    // 0x3F // ?

        // ESC <stuff> [ABFHLM<]    SCS designate character sets

    //case 0x40: // @

    //case 0x41: // A

    case 0x42: // B
        if (m_parse.m_int == ")")
            return DDD2();
        break;

    //case 0x43: // C

    case 0x44: // D
        if (m_parse.m_int == "")
            return IND();
        break;

    case 0x45: // E
        if (m_parse.m_int == "")
            return NEL();
        break;

    //case 0x46: // F
        // ESC SP F      S7C1T send C1 control character to host

    //case 0x47: // G
        // ESC SP G      S8C1T send C1 control character to host

    case 0x48: // H
        if (m_parse.m_int == "")
            return HTS();
        break;

    //case 0x49: // I

    //case 0x4A: // J

    //case 0x4B: // K

    //case 0x4C: // L
        // ESC 0x20 L - ANSI conformance level 1

    case 0x4D: // M
        if (m_parse.m_int == "")
            return RI();
        break;
        // ESC 0x20 M - ANSI conformance level 2

    case 0x4E: // N
        if (m_parse.m_int == "")
            return SS2();
        break;
        // ESC 0x20 N - ANSI conformance level 3

    case 0x4F: // O
        if (m_parse.m_int == "")
            return SS3();
        break;

    //case 0x50: // P
        // ESC P - DCS

    //case 0x51: // Q

    //case 0x52: // R

    //case 0x53: // S

    //case 0x54: // T

    //case 0x55: // U

    //case 0x56: // V

    //case 0x57: // W

    //case 0x58: // X
        // ESC X - SOS

    //case 0x59: // Y

    //case 0x5A: // Z - send vt100 id string?
        // ESC Z - DECID (ignored in later terminals)

    //case 0x5B: // [
        // ESC [ - CSI

    //case 0x5C: // backslash
        // ESC \ - ST

    //case 0x5D: // ]
        // ESC ] - OSC

    //case 0x5E: // ^
        // ESC ^ - PM

    //case 0x5F: // _
        // ESC _ - APC

    case 0x60: // `
        if (m_parse.m_int == "")
            DMI();
        //! @todo Tektronix - normal Z axis and normal (solid)
        break;

    case 0x61: // a
        if (m_parse.m_int == "")
            return INT();
        break;

    case 0x62: // b
        if (m_parse.m_int == "")
            return EMI();
        break;

    case 0x63: // c
        if (m_parse.m_int == "")
            return RIS();
        break;

    case 0x64: // d
        if (m_parse.m_int == "")
            return CMD();
        break;

    // 0x65 e
    // 0x66 f
    // 0x67 g - visual bell?
    // 0x68 h
    // 0x69 i
    // 0x6A j
    // 0x6B k - title definition string?

    case 0x6C: // l                           // ???
        break;

    case 0x6D: // m                           // ???
        break;

    case 0x6E: // n
        if (m_parse.m_int == "")
            return LS2();
        break;

    case 0x6F: // o
        if (m_parse.m_int == "")
            return LS3();
        break;

    // p - ESC Pn p - cursor visibility? (6=invis,7=vis)
    // q
    // r
    // s
    // t
    // u
    // v
    // w
    // x
    // y
    // z
    // {

    case 0x7C: // |
        if (m_parse.m_int == "")
            return LS3R();
        break;

    case 0x7D: // }
        if (m_parse.m_int == "")
            return LS2R();
        break;

    case 0x7E: // ~
        if (m_parse.m_int == "")
            return LS1R();
        break;

    // 0x7F // DEL
    // 0x80-0xFF

    }

    return false; //! @todo clean this up

}

}
