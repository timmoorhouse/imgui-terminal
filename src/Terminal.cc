
#include <terminal/Terminal.hh>
//#include "ascii.hh"
#include <iostream>
#include <iomanip>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

#include <imgui.h>

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#include <cstdarg>
#include <cstdio>                       // vfprintf

using namespace ImGui;

namespace terminal {

Terminal::Terminal()
  : m_verbose(false)
  , m_blinkPeriod(1.0)
  , m_blinkPhase(0.0)
{
    reset();
}

Terminal::~Terminal()
{
}

void
Terminal::reset()
{
    _RIS();
    title("Terminal");
}

const char *
Terminal::title()
{
    return m_window_title.c_str();
}

void
Terminal::title(std::string t)
{
    m_window_title = t + "###Terminal";
}

void
Terminal::resize(uint32_t width, uint32_t height)
{
    s().resize(width, height);
}

void
Terminal::write(const char *s, int n)
{
    if (n < 0)
        n = strlen(s);

    for (int i = 0; i < n; i++)
        write(s[i]);
}

void
Terminal::log(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
}

}
