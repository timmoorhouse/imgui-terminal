
#include <terminal/Terminal.hh>
#include "ascii.hh"

namespace terminal {

bool
Terminal::p_dispatch_csi(uint8_t c)
{
    switch (c) {

    // 0x00..0x19

    // DC1
    // DC2
    // DC3
    // DC4
    // NAK
    // SYN
    // ETB
    // CAN
    // EM
    // SUB
    // ESC
    // FS
    // GS
    // RS
    // US

    // 0x20..0x2F are intermediate

    // 0x30..0x3F are parameters

    case 0x40: // @
        if (m_parse.m_int == " ") // 0x20
            return SL(p(0));

        if (m_parse.m_int == "")
            return ICH(p(0));
        break;

    case 0x41: // A
        if (m_parse.m_int == " ") // 0x20
            return SR(p(0));

        if (m_parse.m_int == "")
            return CUU(p(0));
        break;

    case 0x42: // B
        if (m_parse.m_int == " ") // 0x20
            return GSM(p(0), p(1));

        if (m_parse.m_int == "")
            return CUD(p(0));
        break;

    case 0x43: // C
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return GSS(p(0));

        if (m_parse.m_int == "")
            return CUF(p(0));
        break;

    case 0x44: // D
        if (m_parse.m_int == " ") // 0x20
            return FNT(p(0), p(1));

        if (m_parse.m_int == "")
            return CUB(p(0));
        break;

    case 0x45: // E
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return TSS(p(0));

        if (m_parse.m_int == "")
            return CNL(p(0));
        break;

    case 0x46: // F
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.empty()) {
                return JFY();
            } else {
                bool handled = true;
                for (auto p : m_parse.m_parm)
                    handled &= JFY(p);
                return handled;
            }

        if (m_parse.m_int == "")
            return CPL(p(0));
        break;

    case 0x47: // G
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 2)
                return SPI(p(0), p(1));

        if (m_parse.m_int == "")
            return CHA(p(0));
        break;

    case 0x48: // H
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.empty()) {
                return QUAD();
            } else {
                bool handled = true;
                for (auto p : m_parse.m_parm)
                    handled &= QUAD(p);
                return handled;
            }

        if (m_parse.m_int == "")
            return CUP(p(0), p(1));
        break;

    case 0x49: // I
        if (m_parse.m_int == " ") // 0x20
            return SSU(p(0));

        if (m_parse.m_int == "")
            return CHT(p(0));
        break;

    case 0x4A: // J
        if (m_parse.m_int == "?")
            return DECSED(p(0));

        if (m_parse.m_int == " ") // 0x20
            return PFS(p(0));

        if (m_parse.m_int == "")
            return ED(p(0));
        break;

    case 0x4B: // K
        if (m_parse.m_int == "?")
            return DECSEL(p(0));

        if (m_parse.m_int == " ") // 0x20
            return SHS(p(0));

        if (m_parse.m_int == "")
            return EL(p(0));
        break;

    case 0x4C: // L
        if (m_parse.m_int == " ") // 0x20
            return SVS(p(0));

        if (m_parse.m_int == "")
            return IL(p(0));
        break;

    case 0x4D: // M
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return IGS(p(0));

        if (m_parse.m_int == "")
            return DL(p(0));
        break;

    case 0x4E: // N
        if (m_parse.m_int == "")
            return EF(p(0));
        break;

    case 0x4F: // O
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return IDCS(p(0));

        if (m_parse.m_int == "")
            return EA();
        break;

    case 0x50: // P
        if (m_parse.m_int == " ") // 0x20
            return PPA(p(0));

        if (m_parse.m_int == "")
            return DCH(p(0));
        break;

    case 0x51: // Q
        if (m_parse.m_int == " ") // 0x20
            return PPR(p(0));

        if (m_parse.m_int == "")
            return SEE(p(0));
        break;

    case 0x52: // R
        if (m_parse.m_int == " ") // 0x20
            return PPB(p(0));

        if (m_parse.m_int == "")
            return CPR(p(0), p(1));
        break;

    case 0x53: // S
        if (m_parse.m_int == " ") // 0x20
            return SPD(p(0), p(1));

        if (m_parse.m_int == "")
            return SU(p(0));
        break;

    case 0x54: // T
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 2)
                return DTA(p(0), p(1));

        if (m_parse.m_int == "")
            return SD(p(0));
        break;

    case 0x55: // U
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return SLH(p(0));

        if (m_parse.m_int == "")
            return NP(p(0));
        break;

    case 0x56: // V
        if (m_parse.m_int == " ") // 0x20
             if (m_parse.m_parm.size() == 1)
                return SLL(p(0));

        if (m_parse.m_int == "")
            return PP(p(0));
        break;

    case 0x57: // W
        if (m_parse.m_int == "?")
            return DECST8C();

        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return FNK(p(0));

        if (m_parse.m_int == "")
            if (m_parse.m_parm.empty()) {
                return CTC();
            } else {
                bool handled = true;
                for (auto p : m_parse.m_parm)
                    handled &= CTC(p);
                return handled;
            }
        break;

    case 0x58: // X
        if (m_parse.m_int == " ") // 0x20
            return SPQR(p(0));

        if (m_parse.m_int == "")
            return ECH(p(0));
        break;

    case 0x59: // Y
        if (m_parse.m_int == " ") // 0x20
            return SEF(p(0), p(1));

        if (m_parse.m_int == "")
            return CVT(p(0));
        break;

    case 0x5A: // Z
        if (m_parse.m_int == " ") // 0x20
            return PEC(p(0));

        if (m_parse.m_int == "")
            return CBT(p(0));
        break;

    case 0x5B: // [
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return SSW(p(0));

        if (m_parse.m_int == "")
            return SRS(p(0));
        break;

    case 0x5C: // backslash
        if (m_parse.m_int == " ") // 0x20
            return SACS(p(0));

        if (m_parse.m_int == "")
            return PTX(p(0));
        break;

    case 0x5D: // ]
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.empty()) {
                return SAPV();
            } else {
                bool handled = true;
                for (auto p : m_parse.m_parm)
                    handled &= SAPV(p);
                return handled;
            }

        if (m_parse.m_int == "")
            return SDS();
        break;

    case 0x5E: // ^
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return STAB(p(0));

        if (m_parse.m_int == "")
            return SIMD(p(0));
        break;

    case 0x5F: // _
        if (m_parse.m_int == " ") // 0x20
            return GCC(p(0));
        break;

    case 0x60: // `
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return TATE(p(0));

        if (m_parse.m_int == "")
            return HPA(p(0));
        break;

    case 0x61: // a
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return TALE(p(0));

        if (m_parse.m_int == "")
            return HPR(p(0));
        break;

    case 0x62: // b
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return TAC(p(0));

        if (m_parse.m_int == "")
            return REP(p(0));
        break;

    case 0x63: // c
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() >= 1)
                return TCC(p(0), p(1));

        if (m_parse.m_int == ">")
            return DA2(p(0));

        if (m_parse.m_int == "=")
            return DA3(p(0));

        if (m_parse.m_int == "")
            return DA(p(0));

        break;

    case 0x64: // d
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return TSR(p(0));

        if (m_parse.m_int == "")
            return VPA(p(0));
        break;

    case 0x65: // e
        if (m_parse.m_int == " ") // 0x20
            return SCO(p(0));

        if (m_parse.m_int == "")
            return VPR(p(0));
        break;

    case 0x66: // f
        if (m_parse.m_int == " ") // 0x20
            return SRCS(p(0));

        if (m_parse.m_int == "")
            return HVP(p(0), p(1));
        break;

    case 0x67: // g
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return SCS(p(0));

        if (m_parse.m_int == "")
            return TBC(p(0));
        break;

    case 0x68: // h
        // no default parm value
        if (m_parse.m_int == "?") {
            bool handled = true;
            for (auto p : m_parse.m_parm)
                handled &= DECSET(p);
            return handled;
        }

        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return SLS(p(0));

        // no default parm value
        if (m_parse.m_int == "") {
            bool handled = true;
            for (auto p : m_parse.m_parm)
                handled &= SM(p); //! @todo
            return handled;
        }
        break;

    case 0x69: // i
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return SPH(p(0));
        // CSI ? Ps i               MC - DEC private
        if (m_parse.m_int == "")
            return MC(p(0));

        break;

    case 0x6A: // j
        if (m_parse.m_int == " ") // 0x20
            if (m_parse.m_parm.size() == 1)
                return SPL(p(0));

        if (m_parse.m_int == "")
            return HPB(p(0));

        break;

    case 0x6B: // k
       if (m_parse.m_int == " ") // 0x20
           if (m_parse.m_parm.size() == 1)
               return SCP(p(0), p(1));

        if (m_parse.m_int == "")
            return VPB(p(0));

        break;

    case 0x6C: // l
        // no default parm value
        if (m_parse.m_int == "?") {
            bool handled = true;
            for (auto p : m_parse.m_parm)
                handled &= DECRST(p);
            return handled;
        }

        // no default parm value
        if (m_parse.m_int == "")  {
            bool handled = true;
            for (auto p : m_parse.m_parm)
                handled &= RM(p); //! @todo
            return handled;
        }
        break;

    case 0x6D: // m
        if (m_parse.m_int == "")
            if (m_parse.m_parm.empty()) {
                return SGR(0);
            } else {
                bool handled = true;
                for (auto p : m_parse.m_parm)
                    handled &= SGR(p);
                return handled;
            }
        break;

    case 0x6E: // n
        // CSI ? 6 n           DECXCPR extended cursor position report
        // CSI ? Pn n           DSR for DEC private status reports
        if (m_parse.m_int == "")
            return DSR(p(0));
        break;

    case 0x6F: // o
        if (m_parse.m_int == "")
            if (m_parse.m_parm.empty()) {
                return DAQ();
            } else {
                bool handled = true;
                for (auto p : m_parse.m_parm)
                    handled &= DAQ(p);
                return handled;
            }
        break;

    case 0x70: // p
        // CSI Ps - p               DECARR autorepeat rate
        // CSI Pm , p               DECLTOD load time of day
        // CSI Pa $ p               DECRQM request mode
        // CSI ? Ps $ p             DECRQM request private mode
        // CSI Pn " p               DECSCL select conformance level
        // CSI Ps ) p               DECSDPT select digital printed data type
        // CSI Pn * p               DECSPPCS select proprinter character set
        // CSI Pr + p               DECSR secure reset
        // CSI Ps SP p              DECSSCLS set scroll speed
        // CSI Ps p                 DECSSL select set-up language
        // CSI ! p                  DECSTR soft terminal reset
        break;

    case 0x71: // q
        // CSI Ps - q               DECCRTST screensaver timer
        // CSI Pm + q               DECELF enable local functions
        // CSI Ps q                 DECLL load LEDs
        // CSI Ps SP q              DECSCUSR select cursor style
        // CSI Ps $ q               DECSDDT select disconnect delay time
        // CSI Pr * q               DECSRC secure reset confirmation
        // CSI Ps , q               DECTID select terminal id
        if (m_parse.m_int == "\"")
            return DECSCA(p(0));
        break;

    case 0x72: // r
        // CSI ? Pm r

#if 0
        //! @todo iterate over parms !
        if (m_parse.m_int == "$")
            return DECCARA(p(0), p(1), p(2), p(3), p(4));
#endif

        // CSI $ Pm r     DECPCTERM PCTerm or scancode
        // CSI Pn * r       DECSCS select communication speed
        // CSI Ps - r       DECSEST energy saver timing
        // CSI Ps SP r      DECSKCV set key click volume
        // CSI Pm + r       DECSMKR select modifier key reporting
        if (m_parse.m_int == "")
            return DECSTBM(p(0), p(1));
        break;

    case 0x73: // s
        // s - save cursor and attributes?
        // CSI ? Pm s
        // CSI Pm * s                       DECSFC select flow control
        // CSI Ps $ s                       DECSPRTT select printer type
        if (m_parse.m_int == "")
            return DECSLRM(p(0), p(1));
        break;

    case 0x74: // t - resize window?
        // CSI Ps SP t                         DECSWBV set warning bell volume

#if 0
        //! @todo iterate over parms !
        if (m_parse.m_int == "$")
            return DECRARA(p(0), p(1), p(2), p(3), p(4));
#endif

        // CSI Pn t                                 DECSLPP set lines per page
        break;

    case 0x75: // u - restore cursor and attributes?
        // CSI Ps SP u                         DECSMBV set margin bell volume
        // CSI 2 ; Pu $ u                          DECCTR colour table request
        // CSI Ps $ u                           DECRQTSR request terminal state report
        // CSI Ps , u                           DECRQKT request key type
        // CSI & u                              DECRQUPSS request user-preferred supplemental set
        // CSI Pm * u                           DECSCP select communication port
        // CSI Pm " u                           DECSTRL set transmit rate limit
        // CSI Ps $ u                           DECTSR terminal state report
        break;

    case 0x76: // v
        // CSI " v                             DECRQDE request displayed extent

        if (m_parse.m_int == "$")
            return DECCRA(p(0), p(1), p(2), p(3), p(4), p(5), p(6), p(7));

        // CSI Pm , v                           DECRPKT report key type
        // CSI Ps SP v                          DECSLCK set lock key style
        break;

    case 0x77: // w
        // CSI Pm " w                          DECRPDE report displayed extent
        // CSI Pm , w                           DECRQKD request key definition
        // CSI Ps $ w                           DECRQPSR request presentation state report
        // CSI Pm + w                           DECSPP set port parameters
        break;

    case 0x78: // x          // DECREQTPARM - send terminal parameter report
        // CSI & x                             DECES enable session
        // CSI Pm , x                          DECSPMA

        if (m_parse.m_int == "$")
            if (m_parse.m_parm.size() >= 1)
                return DECFRA(p(0), p(1), p(2), p(3), p(4));

        // CSI + x                              DECRQPKFM request program key free memory
        // CSI Ps * x                           DECSACE select attribute change extent
        // CSI Pm , x                           DECSPMA session page memory allocation
        break;

    case 0x79: // y
        // CSI Ps , y                          DECUS update session
        // CSI Pm + y                           DECPKFMR program key free memory report
        // CSI Pm $ y                           DECRPM report mode
        // CSI Pm * y                           DECRQCRA request checksum of rectangular area
        // CSI 4 ; Pm y                         DECTST invoke confidence test
        break;

    case 0x7A: // z
        // CSI Ps , z                          DECDLDA down line load allocation
        // CSI Pm $ z                          DECERA erase rectangular area

        if (m_parse.m_int == "$")
            return DECERA(p(0), p(1), p(2), p(3));

        // CSI Pid * z                         DECINVM invoke macro
        // CSI Ps + z                           DECPKA program key action
        break;

    case 0x7B: // {
        // CSI Ps ) {                          DECSTGLT select colour lookup table
        // CSI Pn * {                           DECMSR macro space report

        if (m_parse.m_int == "$")
            return DECSERA(p(0), p(1), p(2), p(3));

        // CSI Ps , {                           DECSZS select zero symbol
        break;

    case 0x7C: // |
        if (m_parse.m_int == ",")
            return DECAC(p(0), p(1), p(2));
        // CSI Pn $ |                           DECSCPP select columns per page !!!!!!!!!!!!!!!!!!!!!!!!!
        // CSI Pn * |                           DECSNLS set number of lines per screen
        break;

    case 0x7D: // }
        // CSI Pn ' }                          DECIC insert column
        if (m_parse.m_int == ",")
            return DECATC(p(0), p(1), p(2));
        // CSI Pm SP }                          DECKBD keyboard language selection
        // CSI Pm * }                           DECLFKC local function key control
        // CSI Ps $ }                           DECSASD select active status display
        break;

    case 0x7E: // ~
        // CSI Pm , ~                            DECPS play sound
        // CSI Pn ' ~                          DECDC
        // CSI Ps $ ~                           DECSSDT select status display (line) type
        // CSI Ps SP ~                          DECTME terminal mode emulation
        break;

    // DEL

    // 0x80-0xFF

    }

    return false;
}

}
