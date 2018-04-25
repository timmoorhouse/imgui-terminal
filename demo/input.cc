
#include "demo.hh"
#include <imgui.h>
#include <imgui_impl_sdl.h>

using namespace ImGui;

bool
sdl_input_simple(SDL_Event *e)
{
    auto &io = GetIO();

    switch (e->type) {

    case SDL_TEXTINPUT:
        io.AddInputCharactersUTF8(e->text.text);
        return true;

    case SDL_KEYDOWN:
        switch (e->key.keysym.sym) {

        case SDLK_BACKSPACE:
            io.AddInputCharacter(0x08); // BS
            break;

        case SDLK_DELETE:
            io.AddInputCharacter(0x7F); // DEL
            break;

        case SDLK_DOWN:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('B');
            break;

        case SDLK_END:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('4');
            io.AddInputCharacter('~');
            break;

        case SDLK_ESCAPE:
            io.AddInputCharacter(0x1B); // ESC
            break;

        //case SDLK_F1, etc

        case SDLK_HOME:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('1');
            io.AddInputCharacter('~');
            break;

        case SDLK_INSERT:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('2');
            io.AddInputCharacter('~');
            break;

        case SDLK_LEFT:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('D');
            break;

        case SDLK_PAGEDOWN:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('6');
            io.AddInputCharacter('~');
            break;

        case SDLK_PAGEUP:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('5');
            io.AddInputCharacter('~');
            break;

        case SDLK_RETURN:
        case SDLK_RETURN2:
        case SDLK_KP_ENTER:
            io.AddInputCharacter('\n');
            break;

        case SDLK_RIGHT:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('C');
            break;

        case SDLK_UP:
            io.AddInputCharacter(0x1B); // ESC
            io.AddInputCharacter('[');
            io.AddInputCharacter('A');
            break;
        }
        // fallthrough ...
    case SDL_KEYUP:
    	{

    	    int key = e->key.keysym.sym & ~SDLK_SCANCODE_MASK;
    	    io.KeysDown[key] = (e->type == SDL_KEYDOWN);
    	    io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
    	    io.KeyCtrl  = ((SDL_GetModState() & KMOD_CTRL) != 0);
    	    io.KeyAlt   = ((SDL_GetModState() & KMOD_ALT) != 0);
    	    io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
    	}
        return true;

    }

    return ImGui_ImplSdlGL2_ProcessEvent(e);
}

bool
sdl_input_accurate(SDL_Event *e)
{
	//! @todo implement a more accurate input generator
	return false;
}
