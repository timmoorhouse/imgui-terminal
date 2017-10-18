
/*
	Draws heavily upon the sdl_opengl2 example from imgui, with some bits
	added to create a terminal window instead of the imgui sample window.
 */

#include <terminal/Terminal.hh>
#include <imgui.h>
#include "imgui_impl_sdl.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include "demo.hh"

#ifdef __linux__
#include <unistd.h>
#include <pty.h>
#include <fcntl.h>
#endif

using namespace ImGui;

//! @todo menubar with options to spawn shell or vttest, set terminal type, etc

int
main(int argc, char *argv[])
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER))
    {
        printf("Error: %s\n", SDL_GetError());
        return 100;
    }

    // Setup window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    SDL_Window *window = SDL_CreateWindow("ImGui Terminal Demo",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1280,
                                          720,
                                          SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);

    // Setup ImGui binding
    ImGui_ImplSdlGL2_Init(window);

    ImVec4 clear_color = ImColor(114, 144, 154);

    auto &io = GetIO();

#ifdef __linux__
    struct {
    	bool m_show = true;
    	int m_fd;
    	terminal::Terminal m_terminal;
    	pid_t m_pid = -1;
    } shell;
#endif

    struct {
    	bool m_show = false;
    } vttest;

    // Main loop
    bool done = false;
    while (!done)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            sdl_input_simple(&event);
            if (event.type == SDL_QUIT)
                done = true;
        }
        ImGui_ImplSdlGL2_NewFrame(window);

		if (BeginMainMenuBar()) {

			if (BeginMenu("View")) {

#ifdef __linux__
				shell.m_show  |= MenuItem("Shell");
#endif
				vttest.m_show |= MenuItem("VTTest");

				ImGui::EndMenu();
			}

			EndMainMenuBar();
		}


#ifdef __linux__
		if (shell.m_pid > 0) {

			//
			// Receive output from hell, send it to terminal widget
			//

    	    {
    	    	char buf[256];
    	    	ssize_t nbytes = read(shell.m_fd, buf, sizeof(buf));
    	    	for (ssize_t i = 0; i < nbytes; i++)
    	    		shell.m_terminal.write(buf[i]);
    	    }

		}

		if (shell.m_show) {

			//
			// Spawn a shell
			//

			if (shell.m_pid < 0) {
				shell.m_pid = forkpty(&shell.m_fd, nullptr, nullptr, nullptr);

				if (shell.m_pid < 0) {
					perror("forkpty");
					return 101;
				}

				if (!shell.m_pid) {
					//! @todo set term to vt100?
					execl("/bin/bash", nullptr);
					perror("execl");
					return 102;
				}

				fcntl(shell.m_fd, F_SETFL, fcntl(shell.m_fd, F_GETFL, 0) | O_NONBLOCK);
				if (shell.m_fd >= 0)
					write(shell.m_fd, "ls\n", 3); //! @todo
			}

			//
			// Send input to shell
			//

			{
				char buf[256];
				int nread = shell.m_terminal.read(buf, sizeof(buf));
				if (nread) {
					//! @todo check it was written
					write(shell.m_fd, buf, nread);
				}
    		}

			//
			// Draw the terminal widget
			//

			//PushID("Shell");
			if (Begin(shell.m_terminal.title(), &shell.m_show)) {
				shell.m_terminal.draw("Shell", &shell.m_show);

			}
			End();
			//PopID();
		}

#endif

        // Rendering
        glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        Render();
        SDL_GL_SwapWindow(window);
    }

#ifdef __linux__
#endif

    // Cleanup
    ImGui_ImplSdlGL2_Shutdown();
    SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
