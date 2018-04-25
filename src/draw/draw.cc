
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

#include <imgui.h>

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#include <iostream> //! @todo
#include <iomanip> //! @todo
#include <cmath>                        // fmodf

using namespace ImGui;

namespace terminal {

void
Terminal::draw(const char *str_id, bool *p_open)
{

    auto &io = GetIO();
    m_blinkPhase = fmodf(m_blinkPhase + io.DeltaTime, m_blinkPeriod);
    bool blink = (m_blinkPhase < m_blinkPeriod/2);

    //! @todo capture
    CaptureKeyboardFromApp();

    for (int i=0; i < sizeof(io.InputCharacters)/sizeof(ImWchar); i++) {
        ImWchar c = io.InputCharacters[i];
        if (!c)
            break;
        output(c);
    }

    auto &b = s();
    auto dl = GetWindowDrawList();
    auto f = GetFont();
    PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(1.0, 1.0));
    for (int r=1; r <= b.height(true); r++) {

        int s = 1;
        while (s <= b.width(true)) {

            // Find run of identical attributes
            int e = s;
            do {
                e++;
            } while ((e <= b.width(true)) &&
                     (b.attr(r,s,true) == b.attr(r,e,true)) &&
                     ((r != b.row(true)) || (e != b.col(true))));

            auto &a = b.attr(r,s,true);

            auto m = miscAttributes(a);
            ImColor bg = background(a);
            ImColor fg = foreground(a);

            bool reverse = false;
            reverse ^= ((m & ATTR_REVERSE) != 0);
            reverse ^= dec_mode(dec_mode_t::DECSCNM);
            //! @todo visual bell

            if (reverse)
                std::swap(fg, bg);

            //! @todo make a texture???
            ImVec2 tl = GetCursorScreenPos();
            ImVec2 br(tl.x+(e-s)*f->FallbackAdvanceX, tl.y+f->FontSize+1);

            dl->AddRectFilled(tl, br, bg);

            //! @todo draw cursor
            if ((r == b.row(true)) &&
                (s == b.col(true)) &&
                dec_mode(dec_mode_t::DECTCEM)) {
                ImVec2 br(tl.x+f->FallbackAdvanceX, tl.y+f->FontSize);
                dl->AddRect(tl, br, GetColorU32(ImGuiCol_Text)); //! @todo fg?
            }

            bool show = true;
            show &= !(m & ATTR_HIDDEN);
            if (m & ATTR_BLINK)
                show &= blink;

            //! @todo use dl->AddText so we can support dwl, dhl ...

#if 0
            if (show) {
                dl->AddText(font,
                font size,
                pos,
                col,
                )
            }
#endif

            if (show) {
                PushStyleColor(ImGuiCol_Text, static_cast<ImVec4>(fg));
                TextUnformatted(reinterpret_cast<char*>(b.bufp(r,s,true)),
                                reinterpret_cast<char*>(b.bufp(r,e,true)));
                PopStyleColor();

                if (m & ATTR_UNDERLINE)
                    dl->AddLine(ImVec2(tl.x,br.y-2), ImVec2(br.x,br.y-2), fg);
            } else {
                Text("%*s", e-s, "");
            }
            SameLine();

            //! @todo bold
            //! @todo dwl, dhl

            s = e;
        }
        NewLine();

    }
    PopStyleVar();


    Text("R=%u C=%u", b.row(true), b.col(true));
}

}
