
#ifndef TERMINAL_ATTRIBUTE_HH
#define TERMINAL_ATTRIBUTE_HH

#include <cstdint>

namespace terminal {

uint64_t attribute(uint32_t fg, uint32_t bg, uint16_t flags);
uint32_t foreground(uint64_t a);
uint32_t background(uint64_t a);
uint16_t miscAttributes(uint64_t a);

uint64_t set_foreground(uint64_t a, uint32_t fg);
uint64_t set_background(uint64_t a, uint32_t bg);

constexpr uint16_t ATTR_BOLD            = 0x0001;
constexpr uint16_t ATTR_UNDERLINE       = 0x0002;
constexpr uint16_t ATTR_BLINK           = 0x0004;
constexpr uint16_t ATTR_REVERSE         = 0x0008;
constexpr uint16_t ATTR_HIDDEN          = 0x0010;
constexpr uint16_t ATTR_PROTECTED       = 0x0020; // See DECSCA, DECSEL, DECSED

//! @todo these should be line attributes
constexpr uint16_t ATTR_DBL_WIDE        = 0x0040;
constexpr uint16_t ATTR_DBL_HIGH_TOP    = 0x0080;
constexpr uint16_t ATTR_DBL_HIGH_BOTTOM = 0x0100;

}

#endif
