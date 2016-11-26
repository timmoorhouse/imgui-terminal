
#ifndef TERMINAL_ASCII_HH
#define TERMINAL_ASCII_HH

inline namespace ascii {

constexpr char NUL = 0x00;
constexpr char SOH = 0x01;
constexpr char STX = 0x02;
constexpr char ETX = 0x03;
constexpr char EOT = 0x04;
constexpr char ENQ = 0x05;
constexpr char ACK = 0x06;
constexpr char BEL = 0x07;
constexpr char BS  = 0x08;
constexpr char HT  = 0x09; // or TAB
constexpr char LF  = 0x0A;
constexpr char VT  = 0x0B;
constexpr char FF  = 0x0C;
constexpr char CR  = 0x0D;
constexpr char SO  = 0x0E;
constexpr char SI  = 0x0F;
constexpr char DLE = 0x10;
constexpr char DC1 = 0x11;
constexpr char DC2 = 0x12;
constexpr char DC3 = 0x13;
constexpr char DC4 = 0x14;
constexpr char NAK = 0x15;
constexpr char SYN = 0x16;
constexpr char ETB = 0x17;
constexpr char CAN = 0x18;
constexpr char EM  = 0x19;
constexpr char SUB = 0x1A;
constexpr char ESC = 0x1B;
constexpr char FS  = 0x1C;
constexpr char GS  = 0x1D;
constexpr char RS  = 0x1E;
constexpr char US  = 0x1F;

constexpr char DEL = 0x7F;

}

#endif
