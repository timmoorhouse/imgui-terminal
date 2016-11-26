
#ifndef TERMINAL_COLORMAP_HH
#define TERMINAL_COLORMAP_HH

#include <cstdint>
#include <array>

namespace terminal {

constexpr uint8_t NORMAL_BLACK   = 0;
constexpr uint8_t NORMAL_RED     = 1;
constexpr uint8_t NORMAL_GREEN   = 2;
constexpr uint8_t NORMAL_YELLOW  = 3;
constexpr uint8_t NORMAL_BLUE    = 4;
constexpr uint8_t NORMAL_MAGENTA = 5;
constexpr uint8_t NOMRAL_CYAN    = 6;
constexpr uint8_t NORMAL_WHITE   = 7;

constexpr uint8_t BRIGHT_BLACK   = 8;
constexpr uint8_t BRIGHT_RED     = 9;
constexpr uint8_t BRIGHT_GREEN   = 10;
constexpr uint8_t BRIGHT_YELLOW  = 11;
constexpr uint8_t BRIGHT_BLUE    = 12;
constexpr uint8_t BRIGHT_MAGENTA = 13;
constexpr uint8_t BRIGHT_CYAN    = 14;
constexpr uint8_t BRIGHT_WHITE   = 15;

using colormap_t = std::array<uint32_t, 256>;

}

#endif
