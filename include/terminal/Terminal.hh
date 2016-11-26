
#ifndef TERMINAL_TERMINAL_HH
#define TERMINAL_TERMINAL_HH

#include <terminal/ScreenState.hh>
#include <terminal/Mode.hh>
#include <terminal/ParseState.hh>
#include <terminal/colormap.hh>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream> //! @todo

#ifdef format
#error HUH
#endif

namespace terminal {

#if 0
void FooTerminal(const char *str_id, bool *p_open = nullptr);
#endif

/*
	A VT100 style ImGui terminal widget.
 */

class Terminal {

public:

	Terminal();
	~Terminal();

	void draw(const char *str_id, bool *p_open = nullptr);
	void reset();
	void write(const char*, int len = -1);
	void write(uint8_t c);
	int read(char*, int len);

	const char *title();

	// ********************************************************************
	// modes

	bool mode(mode_t);
	void mode(mode_t, bool);

	bool IRM(bool);
	bool LNM(bool);

	bool dec_mode(dec_mode_t);
	void dec_mode(dec_mode_t, bool);

	bool DECARM(bool);
	bool DECAWM(bool);
	bool DECCKM(bool);
	bool DECCOLM(bool);
	bool DECOM(bool);
	bool DECSCLM(bool);
	bool DECSCNM(bool);
	bool DECTCEM(bool);

	// ********************************************************************
	// commands

	bool ACK(); 						// Acknowledge

	bool APC(const std::string&); 		// Application Program Command

	bool BEL(); 						// Bell

	bool BPH(); 						// Break Permitted Here

	bool BS(); 							// Backspace
	bool _BS();

	bool CAN(); 						// Cancel

	bool CBT(uint32_t = 0); 			// Cursor Backward Tabulation
	bool _CBT(uint32_t = 0);

	bool CCH(); 						// Cancel Character

	bool CHA(uint32_t = 0); 			// Cursor Character Absolute
	bool _CHA(uint32_t = 0);

	bool CHT(uint32_t = 0); 			// Cursor Forward Tabulation
	bool _CHT(uint32_t = 0);

	bool CMD(); 						// Coding Method Delimiter

	bool CNL(uint32_t = 0); 			// Cursor Next Line
	bool _CNL(uint32_t = 0);

	bool CPL(uint32_t = 0); 			// Cursor Preceding Line
	bool _CPL(uint32_t = 0);

	//! @todo delete this?
	bool CPR(uint32_t = 0, uint32_t = 0); // Active Position Report
	bool _CPR(uint32_t = 0, uint32_t = 0);

	bool CR(); 							// Carriage Return
	bool _CR();

	bool CTC(uint32_t = 0); 			// Cursor Tabulation Control
	bool _CTC(uint32_t = 0);

	bool CUB(uint32_t = 0); 			// Cursor Left
	bool _CUB(uint32_t = 0);

	bool CUD(uint32_t = 0); 			// Cursor Down
	bool _CUD(uint32_t = 0);

	bool CUF(uint32_t = 0); 			// Cursor Right
	bool _CUF(uint32_t = 0);

	bool CUP(uint32_t = 0, uint32_t = 0); // Cursor Position
	bool _CUP(uint32_t = 0, uint32_t = 0);

	bool CUU(uint32_t = 0); 			// Cursor Up
	bool _CUU(uint32_t = 0);

	bool CVT(uint32_t = 0); 			// Cursor Line Tabulation
	bool _CVT(uint32_t = 0);

	bool DA(uint32_t = 0);				// Device Attributes
	bool _DA(uint32_t = 0);

	bool DA2(uint32_t = 0);				// Secondary Device Attributes
	bool _DA2(uint32_t = 0);

	bool DA3(uint32_t = 0);				// Tertiary Device Attributes
	bool _DA3(uint32_t = 0);

	bool DAQ(uint32_t = 0);				// Define Area Qualification
	bool _DAQ(uint32_t = 0);

	bool DCH(uint32_t = 0); 			// Delete Character
	bool _DCH(uint32_t = 0);

	bool DC1(); 						// Device Control One

	bool DC2(); 						// Device Control Two

	bool DC3(); 						// Device Control Three

	bool DC4(); 						// Device Control Four

	bool DDD1();

	bool DDD2();

	bool DDD3();

	bool DECAC(uint32_t, uint32_t, uint32_t); // Assign Colour
	bool _DECAC(uint32_t, uint32_t, uint32_t);

	bool DECALN();

	bool DECATC(uint32_t, uint32_t, uint32_t); // Alaternate Text Colour
	bool _DECATC(uint32_t, uint32_t, uint32_t);

	bool DECBI();						// Back Index
	bool _DECBI();

	bool DECCARA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0); // Change Attributes in Rectangular Area
	bool _DECCARA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0);

	bool DECCRA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0,
	            uint32_t = 0, uint32_t = 0, uint32_t = 0); // Copy Rectangular Area
	bool _DECCRA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0,
	            uint32_t = 0, uint32_t = 0, uint32_t = 0);

	bool DECDC(uint32_t = 0);			// Delete Column

	bool DECDHL(bool top);
	bool _DECDHL(bool top);

	bool DECDWL();
	bool _DECDWL();

	bool DECERA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0); // Erase Rectangular Area
	bool _DECERA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0);

	bool DECES();						// Enable Session

	bool DECFI();						// Forward Index
	bool _DECFI();

	bool DECFRA(uint32_t, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0); // Fill Rectangular Area
	bool _DECFRA(uint32_t, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0);

	bool DECID(); 						// Terminal ID

	bool DECKPAM(); 					// Application Keypad

	bool DECKPNM(); 					// Normal Keypad

	bool DECRARA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0); // Reverse Attributes in Rectangular Area
	bool _DECRARA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0);

	bool DECRC(); 						// Restore Cursor
	bool _DECRC();

	bool DECRST(uint32_t);
	// use _DECSET(p, false)

	bool DECSC(); 						// Save Cursor
	bool _DECSC();

	bool DECSCA(uint32_t = 0);			// Select Character Protection Attribute
	bool _DECSCA(uint32_t = 0);

	bool DECSDL();

	bool DECSED(uint32_t = 0);			// Selective Erase in Display
	bool _DECSED(uint32_t = 0);

	bool DECSEL(uint32_t = 0);			// Selective Erase in Line
	bool _DECSEL(uint32_t = 0);

	bool DECSERA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0); // Selective Erase Rectangular Area
	bool _DECSERA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0);

	bool DECSET(uint32_t);
	bool _DECSET(uint32_t, bool);

	bool DECSLRM(uint32_t = 0, uint32_t = 0);
	bool _DECSLRM(uint32_t = 0, uint32_t = 0);

	bool DECSPMA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0); // Session Page Memory Allocation
	bool _DECSPMA(uint32_t = 0, uint32_t = 0, uint32_t = 0, uint32_t = 0);

	bool DECST8C();
	bool _DECST8C();

	bool DECSTBM(uint32_t = 0, uint32_t = 0);
	bool _DECSTBM(uint32_t = 0, uint32_t = 0);

	bool DECSTR();

	bool DECSWL();
	bool _DECSWL();

	bool DECTST(uint32_t = 0);
	bool _DECTST(uint32_t = 0);

	bool DECUDK();

	bool DECUS(uint32_t = 0);				// Update Session
	bool _DECUS(uint32_t = 0);

	bool DL(uint32_t = 0); 				// Delete Line
	bool _DL(uint32_t = 0);

	bool DLE(); 						// Data Link Escape

	bool DMI(); 						// Disable Manual Input

	bool DSR(uint32_t = 0); 			// Device Status Report
	bool _DSR(uint32_t = 0);

	bool DTA(uint32_t, uint32_t); 		// Dimension Text Area

	bool EA(); 							// Erase in Area

	bool ECH(uint32_t = 0); 			// Erase Character
	bool _ECH(uint32_t = 0);

	bool ED(uint32_t = 0); 				// Erase in Page
	bool _ED(uint32_t = 0);

	bool EF(uint32_t = 0); 				// Erase in Field
	bool _EF(uint32_t = 0);

	bool EL(uint32_t = 0); 				// Erase in Line
	bool _EL(uint32_t = 0);

	bool EM();  						// End of Medium

	bool EMI(); 						// Enable Manual Input

	bool ENQ(); 						// Enquiry

	bool EOT(); 						// End of Transmission

	bool EPA(); 						// End of Guarded Area

	bool ESA(); 						// End of Selected Area

	bool ETB(); 						// End of Transmission Block

	bool ETX(); 						// End of Text

	bool FF(); 							// Form Feed

	//! @todo delete this?
	bool FNK(uint32_t); 				// Function Key

	bool FNT(uint32_t = 0, uint32_t = 0); // Font Selection
	bool _FNT(uint32_t = 0, uint32_t = 0);

	bool GCC(uint32_t = 0); 			// Graphic Character Combination
	bool _GCC(uint32_t = 0);

	bool GSM(uint32_t = 0, uint32_t = 0); // Graphic Size Modification
	bool _GSM(uint32_t = 0, uint32_t = 0);

	bool GSS(uint32_t); 				// Graphic Size Selection

	bool HPA(uint32_t = 0); 			// Character Position Absolute

	bool HPB(uint32_t = 0); 			// Character Position Backward

	bool HPR(uint32_t = 0); 			// Character Position Forward

	bool HT();  						// Character Tabulation

	bool HTJ(); 						// Character Tabulation with Justification

	bool HTS(); 						// Character Tabulation Set
	bool _HTS();

	bool HVP(uint32_t = 0, uint32_t = 0); // Character and Line Position

	bool ICH(uint32_t = 0); 			// Insert Character
	bool _ICH(uint32_t = 0);

	bool IDCS(uint32_t); 				// Identify Device Control String

	bool IGS(uint32_t); 				// Identify Graphic Subrepertoire

	bool IL(uint32_t = 0); 				// Insert Line
	bool _IL(uint32_t = 0);

	bool IND();
	bool _IND();

	bool INT(); 						// Interrupt

	bool IS1(); 						// Information Separator One (US - Unit Separator)

	bool IS2(); 						// Information Separator Two (RS - Record Separator)

	bool IS3(); 						// Information Separator Three (GS - Group Separator)

	bool IS4(); 						// Information Separator Four (FS - File Separator)

	bool JFY(uint32_t = 0); 			// Justify
	bool _JFY(uint32_t = 0);

	bool LF();  						// Line Feed
	bool _LF();

	bool LS0(); 						// Locking-Shift Zero

	bool LS1(); 						// Locking-Shift One

	bool LS1R(); 						// Locking-Shift One Right

	bool LS2();  						// Locking-Shift Two

	bool LS2R(); 						// Locking-Shift Two Right

	bool LS3();  						// Locking-Shift Three

	bool LS3R(); 						// Locking-Shift Three Right

	bool MC(uint32_t = 0); 				// Media Copy

	bool MW();  						// Message Waiting

	bool NAK(); 						// Negative Acknowledge

	bool NBH(); 						// No Break Here

	bool NEL(); 						// Next Line

	bool NP(uint32_t = 0); 				// Next Page
	bool _NP(uint32_t = 0);

	bool NUL(); 						// Null

	bool PEC(uint32_t = 0);				// Presentation Expand or Contract
	bool _PEC(uint32_t = 0);

	bool PFS(uint32_t = 0);				// Page Format Selection
	bool _PFS(uint32_t = 0);

	bool PLD(); 						// Partial Line Forward

	bool PLU(); 						// Partial Line Backward

	bool PM(const std::string&); 		// Privacy Message

	bool PP(uint32_t = 0);  			// Preceding Page
	bool _PP(uint32_t = 0);

	bool PPA(uint32_t = 0); 			// Page Position Absolute
	bool _PPA(uint32_t = 0);

	bool PPB(uint32_t = 0); 			// Page Position Backward
	bool _PPB(uint32_t = 0);

	bool PPR(uint32_t = 0); 			// Page Position Forward
	bool _PPR(uint32_t = 0);

	bool PTX(uint32_t = 0); 			// Parallel Texts
	bool _PTX(uint32_t = 0);

	bool PU1(); 						// Private Use One

	bool PU2(); 						// Private Use Two

	bool QUAD(uint32_t = 0); 			// Quad
	bool _QUAD(uint32_t = 0);

	bool REP(uint32_t = 0);  			// Repeat
	bool _REP(uint32_t = 0);

	bool RI();  						// Reverse Line Feed
	bool _RI();

	bool RIS(); 						// Reset to Initial State
	bool _RIS();

	bool RM(uint32_t); 					// Reset Mode
	// use _SM(p, false)

	bool SACS(uint32_t = 0); 			// Set Additional Character Separation
	bool _SACS(uint32_t = 0);

	bool SAPV(uint32_t = 0); 			// Select Alternative Presentation Variants
	bool _SAPV(uint32_t = 0);

	bool SCI(); 						// Single Character Introducer

	bool SCO(uint32_t = 0); 			// Select Character Orientation
	bool _SCO(uint32_t = 0);

	bool SCP(uint32_t, uint32_t); 		// Select Character Path

	bool SCS(uint32_t); 				// Set Character Spacing

	bool SD(uint32_t = 0); 				// Scroll Down
	bool _SD(uint32_t = 0);

	bool SDS(); 						// Start Directed String

	bool SEE(uint32_t = 0); 			// Select Editing Extent
	bool _SEE(uint32_t = 0);

	bool SEF(uint32_t = 0, uint32_t = 0); // Sheet Eject and Feed
	bool _SEF(uint32_t = 0, uint32_t = 0);

	bool SGR(uint32_t = 0); 			// Select Graphic Rendition
	bool _SGR(uint32_t = 0);

	bool SHS(uint32_t = 0); 			// Select Character Spacing
	bool _SHS(uint32_t = 0);

	bool SIMD(uint32_t = 0); 			// Select Implicit Movement Direction
	bool _SIMD(uint32_t = 0);

	bool SL(uint32_t = 0); 				// Scroll Left
	bool _SL(uint32_t = 0);

	bool SLH(uint32_t); 				// Set Line Home

	bool SLL(uint32_t); 				// Set Line Limit

	bool SLS(uint32_t); 				// Set Line Spacing

	bool SM(uint32_t); 					// Set Mode
	bool _SM(uint32_t, bool);

	bool SOH(); 						// Start of Heading

	bool SOS(const std::string&); 		// Start of String

	bool SPA(); 						// Start of Guarded Area

	bool SPD(uint32_t = 0, uint32_t = 0); // Select Presentation Directions
	bool _SPD(uint32_t = 0, uint32_t = 0);

	bool SPH(uint32_t); 				// Set Page Home

	bool SPI(uint32_t, uint32_t); 		// Spacing Increment

	bool SPL(uint32_t); 				// Set Page Limit

	bool SPQR(uint32_t = 0); 			// Select Print Quality and Rapidity
	bool _SPQR(uint32_t = 0);

	bool SR(uint32_t = 0); 				// Scroll Right
	bool _SR(uint32_t = 0);

	bool SRCS(uint32_t = 0); 			// Set Reduced Character Separation
	bool _SRCS(uint32_t = 0);

	bool SRS(uint32_t = 0); 			// Start Reversed String
	bool _SRS(uint32_t = 0);

	bool SSA(); 						// Start of Selected Area

	bool SSU(uint32_t = 0); 			// Select Size Unit
	bool _SSU(uint32_t = 0);

	bool SSW(uint32_t); 				// Set Page Width

	bool SS2();  						// Single-Shift Two

	bool SS3();  						// Single-Shift Three

	bool STAB(uint32_t); 				// Selective Tabulation

	bool STS(); 						// Set Transmit State

	bool STX(); 						// Start of Text

	bool SU(uint32_t = 0); 				// Scroll Up
	bool _SU(uint32_t = 0);

	bool SUB(); 						// Substitute

	bool SVS(uint32_t = 0); 			// Select Line Spacing
	bool _SVS(uint32_t = 0);

	bool SYN(); 						// Synchronous Idle

	bool TAC(uint32_t);  				// Tabulation Aligned Centred

	bool TALE(uint32_t); 				// Tabulation Aligned Leading Edge

	bool TATE(uint32_t); 				// Tabulation Aligned Trailing Edge

	bool TBC(uint32_t = 0); 			// Tabulation Clear
	bool _TBC(uint32_t = 0);

	bool TCC(uint32_t, uint32_t = 0);  // Tabulation Centred on Character
	bool _TCC(uint32_t, uint32_t = 0);

	bool TSR(uint32_t); 				// Tabulation Stop Remove

	bool TSS(uint32_t); 				// Thin Space Specification

	bool VPA(uint32_t = 0); 			// Line Position Absolute
	bool _VPA(uint32_t = 0);

	bool VPB(uint32_t = 0); 			// Line Position Backward

	bool VPR(uint32_t = 0); 			// Line Position Forward

	bool VT();  						// Line Tabulation

	bool VTS(); 						// Line Tabulation Set

	// ********************************************************************

private:

	ScreenState m_screen;
	ScreenState &s() { return m_screen; }

	// ********************************************************************

	bool m_verbose;
	std::unordered_map<int, bool> m_mode;
	std::unordered_map<int, bool> m_dec_mode;

	void title(std::string t);

	std::string m_icon_name;
	std::string m_window_title;
	std::string m_log_file;
	std::string m_font_name;

         float m_blinkPeriod;
	float m_blinkPhase;

	void resize(uint32_t width, uint32_t height);

	// ********************************************************************
	// colormap

	static colormap_t s_colormap;

	// ********************************************************************
	// input

	ParseState m_parse;

	void parse();

	// actions for parsing FSM
	bool p_ignore(uint8_t c);
	bool p_control_string(uint8_t c);
	bool p_print(uint8_t c);
	bool p_parameter(uint8_t c);
	bool p_intermediate(uint8_t c);
	bool p_dispatch(uint8_t c);
	bool p_dispatch_esc(uint8_t c);
	bool p_dispatch_csi(uint8_t c);
	bool p_osc_put(uint8_t c);

	bool p_dispatch_dcs();
	bool p_dispatch_osc();

	void p_unhook();
	void p_clear_parms();
	void p_hook();
	//void p_osc_start();

	uint32_t p(uint32_t idx);

	// ********************************************************************
	// output

	std::vector<uint8_t> m_output;
	void output(uint8_t c);
	void output(const char *fmt, ...)
#ifdef __GNUC__
		__attribute__((format(printf,2,3)))
#endif
	;

	// ********************************************************************

protected:

	virtual void log(const char *fmt, ...)
#ifdef __GNUC__
		__attribute__((format(printf,2,3)))
#endif
	;

};

}

#endif
