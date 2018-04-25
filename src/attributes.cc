
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
    16-bit flags (underscore, etc) (TODO)

 */

uint64_t
attribute(uint32_t foreground,
          uint32_t background,
          uint16_t flags)
{
    return ((foreground & IM_COL32(0xFF, 0xFF, 0xFF, 0)) |
            ((uint64_t)(background & IM_COL32(0xFF, 0xFF, 0xFF, 0)) << 24) |
            ((uint64_t)(flags) << 48));
}

uint32_t
foreground(uint64_t a)
{
    return (a & IM_COL32(0xFF, 0xFF, 0xFF, 0)) | IM_COL32(0,0,0,0xFF);
}

#if 0
uint64_t
set_foreground(uint64_t a, uint32_t fg)
{
}
#endif

uint32_t
background(uint64_t a)
{
    return ((a >> 24) & IM_COL32(0xFF, 0xFF, 0xFF, 0)) | IM_COL32(0,0,0,0xFF);
}

#if 0
uint64_t
set_background(uint64_t a, uint32_t bg)
{
}
#endif

uint16_t
miscAttributes(uint64_t a)
{
    return (a >> 48);
}

}
