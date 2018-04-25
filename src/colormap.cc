
#include <terminal/Terminal.hh>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

#include <imgui.h>

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

using namespace ImGui;

namespace terminal {

/*

    Attribute bits:

    24-bit foreground
    24-bit background
    16-bit flags (underscore, etc)

 */

//! @todo
#define RGB555(i)

//! @todo
#define GRAYSCALE(i) IM_COL32(i*10, i*10, i*10, 0)

std::array<uint32_t, 256>
Terminal::s_colormap = {

    // Standard colours, following the xterm values
    // 0x00
    IM_COL32(  0,   0,   0, 0),
    IM_COL32(205,   0,   0, 0),
    IM_COL32(  0, 205,   0, 0),
    IM_COL32(205, 205,   0, 0),
    IM_COL32(  0,   0, 238, 0),
    IM_COL32(205,   0, 205, 0),
    IM_COL32(  0, 205, 205, 0),
    IM_COL32(229, 229, 229, 0),

    // High intensity colours, following the xterm values
    // 0x08
    IM_COL32(127, 127, 127, 0),
    IM_COL32(255,   0,   0, 0),
    IM_COL32(  0, 255,   0, 0),
    IM_COL32(255, 255,   0, 0),
    IM_COL32( 92,  92, 255, 0),
    IM_COL32(255,   0, 255, 0),
    IM_COL32(  0, 255, 255, 0),
    IM_COL32(255, 255, 255, 0),

    // 0x10
    //! @todo

    // 0x18
    //! @todo

    // 0x20
    //! @todo

    // 0x28
    //! @todo

    // 0x30
    //! @todo

    // 0x38
    //! @todo

    // 0x40
    //! @todo

    // 0x48
    //! @todo

    // 0x50
    //! @todo

    // 0x58
    //! @todo

    // 0x60
    //! @todo

    // 0x68
    //! @todo

    // 0x70
    //! @todo

    // 0x78
    //! @todo

    // 0x80
    //! @todo

    // 0x88
    //! @todo

    // 0x90
    //! @todo

    // 0x98
    //! @todo

    // 0xA0
    //! @todo

    // 0xA8
    //! @todo

    // 0xB0
    //! @todo

    // 0xB8
    //! @todo

    // 0xC0
    //! @todo

    // 0xC8
    //! @todo

    // 0xD0
    //! @todo

    // 0xD8
    //! @todo

    // 0xE0
    //! @todo

    // 0xE8
    GRAYSCALE(0),
    GRAYSCALE(1),
    GRAYSCALE(2),
    GRAYSCALE(3),
    GRAYSCALE(4),
    GRAYSCALE(5),
    GRAYSCALE(6),
    GRAYSCALE(7),

    // 0xF0
    GRAYSCALE(8),
    GRAYSCALE(9),
    GRAYSCALE(10),
    GRAYSCALE(11),
    GRAYSCALE(12),
    GRAYSCALE(13),
    GRAYSCALE(14),
    GRAYSCALE(15),

    // 0xF8
    GRAYSCALE(16),
    GRAYSCALE(17),
    GRAYSCALE(18),
    GRAYSCALE(19),
    GRAYSCALE(20),
    GRAYSCALE(21),
    GRAYSCALE(22),
    GRAYSCALE(23),

};

}
