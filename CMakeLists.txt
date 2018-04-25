
cmake_minimum_required(VERSION 3.0)

project(ImGuiTerminal VERSION 0.1.0.0)

#set(CMAKE_MODULE_PATH
#	"${PROJECT_SOURCE_DIR}/CMake"
#	${CMAKE_MODULE_PATH}
#)

find_package(SDL2)
find_package(OpenGL)

set(${PROJECT_NAME}_ImGui_SOURCE_DIR
    "external/imgui"
    CACHE FILEPATH
    "Location of ImGui source")

# TODO: imterm currently only works on Linux ...
cmake_dependent_option(${PROJECT_NAME}_BUILD_DEMOS
                       "Build demo programs"
                       ON "UNIX;SDL2_FOUND;OPENGL_FOUND" OFF)

option(${PROJECT_NAME}_UNITY_BUILD "Unity build" OFF)

include(GenerateExportHeader)

add_library(imgui-terminal STATIC src/Terminal.cc)

if(${PROJECT_NAME}_UNITY_BUILD)
    target_sources(imgui-terminal PRIVATE src/Terminal_unity.cc)
else()
    target_sources(imgui-terminal PRIVATE

        src/attributes.cc
        src/colormap.cc
        src/CursorState.cc
        src/ParseState.cc
        src/ScreenState.cc
#        src/Terminal.cc

        src/commands/C0/ACK.cc
        src/commands/C0/CAN.cc
        src/commands/C0/DC1.cc
        src/commands/C0/DC2.cc
        src/commands/C0/DC3.cc
        src/commands/C0/DC4.cc
        src/commands/C0/DLE.cc
        src/commands/C0/EM.cc
        src/commands/C0/ENQ.cc
        src/commands/C0/EOT.cc
        src/commands/C0/ETB.cc
        src/commands/C0/ETX.cc
        src/commands/C0/IS1.cc
        src/commands/C0/IS2.cc
        src/commands/C0/IS3.cc
        src/commands/C0/IS4.cc
        src/commands/C0/NAK.cc
        src/commands/C0/NUL_.cc
        src/commands/C0/SOH.cc
        src/commands/C0/STX.cc
        src/commands/C0/SUB.cc
        src/commands/C0/SYN.cc

        src/commands/C1/BPH.cc
        src/commands/C1/CCH.cc
        src/commands/C1/EPA.cc
        src/commands/C1/MW.cc
        src/commands/C1/NBH.cc
        src/commands/C1/PLD.cc
        src/commands/C1/PLU.cc
        src/commands/C1/PU1.cc
        src/commands/C1/PU2.cc
        src/commands/C1/SCI.cc
        src/commands/C1/SPA.cc
        src/commands/C1/SSA.cc
        src/commands/C1/STS.cc

        src/commands/audible_attributes/BEL.cc
#       src/commands/audible_attributes/DECPS.cc
#       src/commands/audible_attributes/DECSMBV.cc
#       src/commands/audible_attributes/DECSWBV.cc

        src/commands/colour_selection/DECAC.cc
        src/commands/colour_selection/DECATC.cc
#       src/commands/colour_selection/DECATCBM.cc
#       src/commands/colour_selection/DECATCUM.cc
#       src/commands/colour_selection/DECBBSM.cc
#       src/commands/colour_selection/DECCTR.cc
#       src/commands/colour_selection/DECECM.cc
#       src/commands/colour_selection/DECSTGLT.cc

        src/commands/editing/DCH.cc
        src/commands/editing/DECCARA.cc
        src/commands/editing/DECCRA.cc
        src/commands/editing/DECDC.cc
        src/commands/editing/DECERA.cc
        src/commands/editing/DECFRA.cc
#       src/commands/editing/DECIC.cc
        src/commands/editing/DECRARA.cc
#       src/commands/editing/DECSACE.cc
        src/commands/editing/DECSCA.cc
        src/commands/editing/DECSED.cc
        src/commands/editing/DECSEL.cc
        src/commands/editing/DECSERA.cc
        src/commands/editing/DL.cc
        src/commands/editing/ECH.cc
        src/commands/editing/ED.cc
        src/commands/editing/EL.cc
        src/commands/editing/ICH.cc
        src/commands/editing/IL.cc
        src/commands/editing/IRM.cc

#       src/commands/graphic_character_sets/CRM.cc
#       src/commands/graphic_character_sets/DECAUPSS.cc
#       src/commands/graphic_character_sets/DECAUPSS.cc
#       src/commands/graphic_character_sets/DECDLD.cc
#       src/commands/graphic_character_sets/DECDLDA.cc
#       src/commands/graphic_character_sets/DECNRCM.cc
#       src/commands/graphic_character_sets/DECRQUPSS.cc
#       src/commands/graphic_character_sets/DECSZS.cc
#       src/commands/graphic_character_sets/LS.cc
        src/commands/graphic_character_sets/LS0.cc
        src/commands/graphic_character_sets/LS1.cc
        src/commands/graphic_character_sets/LS1R.cc
        src/commands/graphic_character_sets/LS2.cc
        src/commands/graphic_character_sets/LS2R.cc
        src/commands/graphic_character_sets/LS3.cc
        src/commands/graphic_character_sets/LS3R.cc
#       src/commands/graphic_character_sets/S7C1T.cc
#       src/commands/graphic_character_sets/S8C1T.cc
#       src/commands/graphic_character_sets/SCODPCC.cc
#       src/commands/graphic_character_sets/SCS.cc
        src/commands/graphic_character_sets/SS2.cc
        src/commands/graphic_character_sets/SS3.cc

        src/commands/keyboard_processing/DECARM.cc
#       src/commands/keyboard_processing/DECARR.cc
#       src/commands/keyboard_processing/DECBKM.cc
#       src/commands/keyboard_processing/DECCAPSLK.cc
#       src/commands/keyboard_processing/DECCKD.cc
        src/commands/keyboard_processing/DECCKM.cc
#       src/commands/keyboard_processing/DECEKBD.cc
#       src/commands/keyboard_processing/DECELF.cc
#       src/commands/keyboard_processing/DECESKM.cc
#       src/commands/keyboard_processing/DECHEBM.cc
#       src/commands/keyboard_processing/DECHEM.cc
#       src/commands/keyboard_processing/DECKBD.cc
#       src/commands/keyboard_processing/DECKBUM.cc
#       src/commands/keyboard_processing/DECKLHIM.cc
        src/commands/keyboard_processing/DECKPAM.cc
#       src/commands/keyboard_processing/DECKPM.cc
        src/commands/keyboard_processing/DECKPNM.cc
#       src/commands/keyboard_processing/DECLFKC.cc
#       src/commands/keyboard_processing/DECNAKB.cc
#       src/commands/keyboard_processing/DECNKM.cc
#       src/commands/keyboard_processing/DECNUMLK.cc
#       src/commands/keyboard_processing/DECPAK.cc
#       src/commands/keyboard_processing/DECPFK.cc
#       src/commands/keyboard_processing/DECPKA.cc
#       src/commands/keyboard_processing/DECPKFMR.cc
#       src/commands/keyboard_processing/DECRPAK.cc
#       src/commands/keyboard_processing/DECRPFK.cc
#       src/commands/keyboard_processing/DECRPKT.cc
#       src/commands/keyboard_processing/DECRQKD.cc
#       src/commands/keyboard_processing/DECRQKT.cc
#       src/commands/keyboard_processing/DECRQPKFM.cc
#       src/commands/keyboard_processing/DECSKCV.cc
#       src/commands/keyboard_processing/DECSLCK.cc
#       src/commands/keyboard_processing/DECSMKR.cc
#       src/commands/keyboard_processing/DECUDK.cc
#       src/commands/keyboard_processing/KAM.cc
#       src/commands/keyboard_processing/SCODFK.cc

#       src/commands/printer/DECIPEM.cc
#       src/commands/printer/DECPEX.cc
#       src/commands/printer/DECPFF.cc
#       src/commands/printer/DECSDPT.cc
#       src/commands/printer/DECSPPCS.cc
#       src/commands/printer/DECSPRTT.cc
        src/commands/printer/MC.cc

        src/commands/reports/DDD1.cc
        src/commands/reports/DDD2.cc
        src/commands/reports/DDD3.cc
#       src/commands/reports/DECCKSR.cc
#       src/commands/reports/DECCTR.cc
#       src/commands/reports/DECDMAC.cc
#       src/commands/reports/DECINVM.cc
#       src/commands/reports/DECMSR.cc
#       src/commands/reports/DECPSR.cc
#       src/commands/reports/DECRPM.cc
#       src/commands/reports/DECRPSS.cc
#       src/commands/reports/DECRQCRA.cc
#       src/commands/reports/DECRQM.cc
#       src/commands/reports/DECRQPSR.cc
#       src/commands/reports/DECRQSS.cc
#       src/commands/reports/DECRQTSR.cc
#       src/commands/reports/DECRSPS.cc
#       src/commands/reports/DECRSTS.cc
#       src/commands/reports/DECTABSR.cc
#       src/commands/reports/DECTSR.cc
        src/commands/reports/DSR.cc

        src/commands/session_management/DECES.cc
        src/commands/session_management/DECSPMA.cc
        src/commands/session_management/DECUS.cc

#       src/commands/terminal_communications/DECSCP.cc
#       src/commands/terminal_communications/DECSCS.cc
#       src/commands/terminal_communications/DECSPP.cc
#       src/commands/terminal_communications/DECSTRL.cc
#       src/commands/terminal_communications/DECXRLM.cc

#       src/commands/terminal_management/CRM.cc
        src/commands/terminal_management/DA.cc
        src/commands/terminal_management/DA2.cc
        src/commands/terminal_management/DA3.cc
#       src/commands/terminal_management/DECAAM.cc
#       src/commands/terminal_management/DECANM.cc
#       src/commands/terminal_management/DECCANSM.cc
#       src/commands/terminal_management/DECCRTSM.cc
#       src/commands/terminal_management/DECCRTST.cc
#       src/commands/terminal_management/DECHWUM.cc
        src/commands/terminal_management/DECID.cc
#       src/commands/terminal_management/DECLANS.cc
#       src/commands/terminal_management/DECLBAN.cc
#       src/commands/terminal_management/DECLTOD.cc
#       src/commands/terminal_management/DECNCSM.cc
#       src/commands/terminal_management/DECPCTERM.cc
#       src/commands/terminal_management/DECRPM.cc
        src/commands/terminal_management/DECRST.cc
#       src/commands/terminal_management/DECRPTUI.cc
#       src/commands/terminal_management/DECSASD.cc
#       src/commands/terminal_management/DECSCL.cc
#       src/commands/terminal_management/DECSEST.cc
        src/commands/terminal_management/DECSET.cc
#       src/commands/terminal_management/DECSR.cc
#       src/commands/terminal_management/DECSRC.cc
#       src/commands/terminal_management/DECSSDT.cc
#       src/commands/terminal_management/DECSSL.cc
#       src/commands/terminal_management/DECSTR.cc
#       src/commands/terminal_management/DECSTUI.cc
#       src/commands/terminal_management/DECTID.cc
#       src/commands/terminal_management/DECTME.cc
        src/commands/terminal_management/DECTST.cc
        src/commands/terminal_management/RIS.cc
        src/commands/terminal_management/RM.cc
        src/commands/terminal_management/SM.cc
#       src/commands/terminal_management/SRM.cc

#       src/commands/terminal_synchronization/DC1.cc
#       src/commands/terminal_synchronization/DC3.cc
#       src/commands/terminal_synchronization/DECHDPXM.cc
#       src/commands/terminal_synchronization/DECMCM.cc
#       src/commands/terminal_synchronization/DECNULM.cc
#       src/commands/terminal_synchronization/DECSDDT.cc
#       src/commands/terminal_synchronization/DECSFC.cc

        src/commands/text_processing/BS.cc
        src/commands/text_processing/CBT.cc
        src/commands/text_processing/CHA.cc
        src/commands/text_processing/CHT.cc
        src/commands/text_processing/CNL.cc
        src/commands/text_processing/CPL.cc
        src/commands/text_processing/CPR.cc
        src/commands/text_processing/CR.cc
        src/commands/text_processing/CTC.cc
        src/commands/text_processing/CUB.cc
        src/commands/text_processing/CUD.cc
        src/commands/text_processing/CUF.cc
        src/commands/text_processing/CUP.cc
        src/commands/text_processing/CUU.cc
        src/commands/text_processing/CVT.cc
        src/commands/text_processing/DECAWM.cc
        src/commands/text_processing/DECBI.cc
#       src/commands/text_processing/DECCIR.cc
        src/commands/text_processing/DECCOLM.cc
        src/commands/text_processing/DECFI.cc
#       src/commands/text_processing/DECLRMM.cc
#       src/commands/text_processing/DECNCSM.cc
        src/commands/text_processing/DECOM.cc
        src/commands/text_processing/DECRC.cc
#       src/commands/text_processing/DECRLCM.cc
#       src/commands/text_processing/DECRLM.cc
        src/commands/text_processing/DECSC.cc
        src/commands/text_processing/DECSCLM.cc
#       src/commands/text_processing/DECSCPP.cc
#       src/commands/text_processing/DECSCUSR.cc
#       src/commands/text_processing/DECSLPP.cc
        src/commands/text_processing/DECSLRM.cc
#       src/commands/text_processing/DECSSCLS.cc
        src/commands/text_processing/DECST8C.cc
        src/commands/text_processing/DECSTBM.cc
        src/commands/text_processing/DECTCEM.cc
#       src/commands/text_processing/DECXCPR.cc
        src/commands/text_processing/FF.cc
        src/commands/text_processing/HPA.cc
        src/commands/text_processing/HPB.cc
        src/commands/text_processing/HPR.cc
        src/commands/text_processing/HT.cc
        src/commands/text_processing/HTJ.cc
        src/commands/text_processing/HTS.cc
        src/commands/text_processing/HVP.cc
        src/commands/text_processing/IND.cc
        src/commands/text_processing/LF.cc
        src/commands/text_processing/LNM.cc
        src/commands/text_processing/NEL.cc
        src/commands/text_processing/NP.cc
        src/commands/text_processing/PP.cc
        src/commands/text_processing/PPA.cc
        src/commands/text_processing/PPB.cc
        src/commands/text_processing/PPR.cc
        src/commands/text_processing/RI.cc
#       src/commands/text_processing/SCORC.cc
#       src/commands/text_processing/SCOSC.cc
        src/commands/text_processing/TAC.cc
        src/commands/text_processing/TALE.cc
        src/commands/text_processing/TATE.cc
        src/commands/text_processing/TBC.cc
        src/commands/text_processing/TCC.cc
        src/commands/text_processing/TSR.cc
        src/commands/text_processing/VPA.cc
        src/commands/text_processing/VPB.cc
        src/commands/text_processing/VPR.cc
        src/commands/text_processing/VT.cc
        src/commands/text_processing/VTS.cc

        src/commands/visual_attributes/DECDHL.cc
        src/commands/visual_attributes/DECDWL.cc
        src/commands/visual_attributes/DECSCNM.cc
        src/commands/visual_attributes/DECSWL.cc
        src/commands/visual_attributes/SGR.cc

#       src/commands/window_management/DECARSM.cc
#       src/commands/window_management/DECFWM.cc
#       src/commands/window_management/DECHCCM.cc
#       src/commands/window_management/DECPCCM.cc
#       src/commands/window_management/DECRPDE.cc
#       src/commands/window_management/DECRPL.cc
#       src/commands/window_management/DECRQDE.cc
#       src/commands/window_management/DECSIN.cc
#       src/commands/window_management/DECSNLS.cc
#       src/commands/window_management/DECSWT.cc
#       src/commands/window_management/DECVCCM.cc
        src/commands/window_management/SD.cc
        src/commands/window_management/SL.cc
        src/commands/window_management/SR.cc
        src/commands/window_management/SU.cc

        src/commands/APC.cc
        src/commands/CMD.cc
        src/commands/DAQ.cc
        src/commands/DECALN.cc
        src/commands/DMI.cc
        src/commands/DTA.cc
        src/commands/EA.cc
        src/commands/EF.cc
        src/commands/EMI.cc
        src/commands/ESA.cc
        src/commands/FNK.cc
        src/commands/FNT.cc
        src/commands/GCC.cc
        src/commands/GSM.cc
        src/commands/GSS.cc
        src/commands/IDCS.cc
        src/commands/IGS.cc
        src/commands/INT.cc
        src/commands/JFY.cc
        src/commands/PEC.cc
        src/commands/PFS.cc
        src/commands/PM.cc
        src/commands/PTX.cc
        src/commands/QUAD.cc
        src/commands/REP.cc
        src/commands/SACS.cc
        src/commands/SAPV.cc
        src/commands/SCO.cc
        src/commands/SCP.cc
        src/commands/SCS.cc
        src/commands/SDS.cc
        src/commands/SEE.cc
        src/commands/SEF.cc
        src/commands/SHS.cc
        src/commands/SIMD.cc
        src/commands/SLH.cc
        src/commands/SLL.cc
        src/commands/SLS.cc
        src/commands/SPD.cc
        src/commands/SPH.cc
        src/commands/SPI.cc
        src/commands/SPL.cc
        src/commands/SPQR.cc
        src/commands/SRCS.cc
        src/commands/SRS.cc
        src/commands/SSU.cc
        src/commands/SSW.cc
        src/commands/STAB.cc
        src/commands/SVS.cc
        src/commands/TSS.cc

        src/draw/draw.cc

        src/input/parse.cc
        src/input/dispatch.cc
        src/input/dispatch_csi.cc
        src/input/dispatch_dcs.cc
        src/input/dispatch_esc.cc
        src/input/dispatch_osc.cc

        src/mode/mode.cc

        src/output/output.cc
    )
endif()

target_include_directories(imgui-terminal
    PUBLIC
        include
    PRIVATE
        "${${PROJECT_NAME}_ImGui_SOURCE_DIR}"
)

install(TARGETS imgui-terminal
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

if(Terminal_BUILD_DEMOS)

    add_executable(imterm
        demo/main.cc
        demo/input.cc

        "${${PROJECT_NAME}_ImGui_SOURCE_DIR}/imgui.cpp"
        "${${PROJECT_NAME}_ImGui_SOURCE_DIR}/imgui_draw.cpp"
        "${${PROJECT_NAME}_ImGui_SOURCE_DIR}/examples/sdl_opengl2_example/imgui_impl_sdl.cpp"
    )

    target_include_directories(imterm
        PRIVATE
            "${${PROJECT_NAME}_ImGui_SOURCE_DIR}"
        	"${${PROJECT_NAME}_ImGui_SOURCE_DIR}/examples/sdl_opengl2_example"
        	${SDL2_INCLUDE_DIR}
        	${OPENGL_INCLUDE_DIR}
    )

    target_link_libraries(imterm
        PRIVATE
            imgui-terminal
        	${SDL2_LIBRARY}
        	${OPENGL_LIBRARIES}
    )

    if(UNIX)
        target_link_libraries(imterm PRIVATE util)
    endif()

    install(TARGETS imterm
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
    )

endif()
