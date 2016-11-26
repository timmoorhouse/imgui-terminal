
#ifndef TERMINAL_MODE_HH
#define TERMINAL_MODE_HH

namespace terminal {

enum class mode_t : uint8_t {
	GATM =  1, // Guarded Area Transfer Mode
	KAM  =  2, // Keyboard Action Mode
	CRM  =  3, // Control Representation Mode
	IRM  =  4, // Insertion Replacement Mode
	SRTM =  5, // Status Report Transfer Mode
	ERM  =  6, // Erasure Mode
	VEM  =  7, // Line Editing Mode
	BDSM =  8, // Bi-Directional Support Mode
	DCSM =  9, // Device Component Select Mode
	HEM  = 10, // Character Editing Mode
	PUM  = 11, // Positioning Unit Mode
	SRM  = 12, // Send/Receive Mode
	FEAM = 13, // Format Effector Action Mode
	FETM = 14, // Format Effector Transfer Mode
	MATM = 15, // Multiple Area Transfer Mode
	TTM  = 16, // Transfer Termination Mode
	SATM = 17, // Selected Area Transfer Mode
	TSM  = 18, // Tabulation Stop Mode
	// 19 was EBM - Editing Boundary Mode
	LNM  = 20, // Line Feed / New Line Mode (deprecated?)
	GRCM = 21, // Graphic Rendition Combination Mode
	ZDM  = 22  // Zero Default Mode
};

constexpr bool BSDM_EXPLICIT = false;
constexpr bool BDSM_IMPLICIT = true;

constexpr bool CRM_CONTROL = false;
constexpr bool CRM_GRAPHIC = true;

constexpr bool DCSM_PRESENTATION = false;
constexpr bool DCSM_DATA = true;

constexpr bool ERM_PROTECT = false;
constexpr bool ERM_ALL = true;

constexpr bool FEAM_EXECUTE = false;
constexpr bool FEAM_STORE = true;

constexpr bool FETM_INSERT = false;
constexpr bool FETM_EXCLUDE = true;

constexpr bool GATM_GUARD = false;
constexpr bool GATM_ALL = true;

constexpr bool HEM_FOLLOWING = false;
constexpr bool HEM_PRECEDING = true;

constexpr bool IRM_REPLACE = false;
constexpr bool IRM_INSERT = true;

constexpr bool KAM_ENABLED = false;
constexpr bool KAM_DISABLED = true;

constexpr bool MATM_SINGLE = false;
constexpr bool MATM_MULTIPLE = true;

constexpr bool PUM_CHARACTER = false;
constexpr bool PUM_SIZE = true;

constexpr bool SATM_SELECT = false;
constexpr bool SATM_ALL = true;

constexpr bool SRM_MONITOR = false;
constexpr bool SRM_SIMULTANEOUS = true;

constexpr bool SRTM_NORMAL = false;
constexpr bool SRTM_DIAGNOSTIC = true;

constexpr bool TSM_MULTIPLE = false;
constexpr bool TSM_SINGLE = true;

constexpr bool TTM_CURSOR = false;
constexpr bool TTM_ALL = true;

constexpr bool VEM_FOLLOWING = false;
constexpr bool VEM_PRECEDING = true;

constexpr bool ZDM_ZERO = false;
constexpr bool ZDM_DEFAULT = true;


enum class dec_mode_t
{
    DECCKM    =   1, // cursor key
    DECANM    =   2, // ANSI (vt52) mode
    DECCOLM   =   3, // 80/132 columns per page
    DECSCLM   =   4, // scrolling
    DECSCNM   =   5, // screen mode light or dark
    DECOM     =   6, // origin
    DECAWM    =   7, // auto wrap
    DECARM    =   8, // auto repeat
    // 9 - xterm: don't send mouse X & Y on button press
    DECPFF    =  18, // print form feed
    DECPEX    =  19, // print extent
    DECTCEM   =  25, // terminal cursor enable
    DECRLM    =  34, // right to left
    DECHEBM   =  35, // hebrew/N-A keyboard mapping
    DECHEM    =  36, // hebrew encoding
    // 40 - xterm: disallow 80/132 mode
    // 41 - xterm: no more(1) fix
    DECNRCM   =  42, // national replacement character set
    // 44 - xterm: turn off margin bell
    // 45 - xterm: no reverse wraparound mode
    // 46 - xterm: stop logging
    // 47 - xterm: use normal screen buffer
    DECIPEM   =  48, // IBM proprinter emulation
    DECNAKB   =  57, // greek/N-A keyboard mapping
    DECVCCM   =  61, // vertical cursor coupling
    DECPCCM   =  64, // page cursor coupling
    DECNKM    =  66, // numeric keypad
    DECBKM    =  67, // backarrow key
    DECKBUM   =  68, // typewriter or data processing keys
    DECLRMM   =  69, // left right margin mode
    DECXRLM   =  73, // transmit rate limiting
    DECKPM    =  81, // key position mode
    DECNCSM   =  95, // no clearing screen on column change
    DECRLCM   =  96, // right to left copy
    DECCRTSM  =  97, // screensaver
    DECARSM   =  98, // auto resize
    DECMCM    =  99, // modem control
    DECAAM    = 100, //
    DECCANSM  = 101, // conceal answerback message
    DECNULM   = 102, // discard NUL
    DECHDPXM  = 103, // half duplex
    DECESKM   = 104, // enable secondary keyboard language
    DECOSCNM  = 106, // overscan
    DECNUMLK  = 108, // num lock
    DECCAPSLK = 109, // caps lock
    DECKLHIM  = 110, // keyboard LED host indicator mode
    DECFWM    = 111, // framed window
    DECRPL    = 112, // review previous lines
    DECHWUM   = 113, // host wake up
    DECATCUM  = 114, // alternate text colour underline
    DECATCBM  = 115, // alternate text colour blink
    DECBBSM   = 116, // bold and blink style
    DECECM    = 117  // erase colour

    // 1000 - xterm: don't send mouse X & Y on button press and release
    // 1001 - xterm: don't use hilite mouse tracking
    // 1049 ?

};

}

#endif
