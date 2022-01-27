cmake_minimum_required(VERSION 3.0.0)
project(fillets VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(fillets 
src/widget/WiStatusBar.cpp
src/widget/WiPicture.cpp
src/widget/WiPara.cpp
src/widget/WiLabel.cpp
src/widget/WiContainer.cpp
src/widget/WiButton.cpp
src/widget/WiBox.cpp
src/widget/VBox.cpp
src/widget/Slider.cpp
src/widget/Labels.cpp
src/widget/IWidget.cpp
src/widget/HBox.cpp
src/state/PosterState.cpp
src/state/PosterScroller.cpp
src/state/MovieState.cpp
src/state/GameInput.cpp
src/state/DemoMode.cpp
src/state/DemoInput.cpp
src/state/demo-script.cpp
src/plan/Title.cpp
src/plan/SubTitleAgent.cpp
src/plan/StateManager.cpp
src/plan/StateInput.cpp
src/plan/ScriptCmd.cpp
src/plan/Planner.cpp
src/plan/Keymap.cpp
src/plan/KeyDesc.cpp
src/plan/KeyConsole.cpp
src/plan/GameState.cpp
src/plan/FishDialog.cpp
src/plan/dialog-script.cpp
src/plan/ConsoleInput.cpp
src/plan/CommandQueue.cpp
src/option/SelectLang.cpp
src/option/RadioBox.cpp
src/option/OptionsInput.cpp
src/option/MenuOptions.cpp
src/option/MenuHelp.cpp
src/option/HelpInput.cpp
src/menu/WorldMap.cpp
src/menu/worldmap-script.cpp
src/menu/WorldInput.cpp
src/menu/WorldBranch.cpp
src/menu/SolverDrawer.cpp
src/menu/Pedometer.cpp
src/menu/PedoInput.cpp
src/menu/NodeDrawer.cpp
src/menu/LevelNode.cpp
src/menu/LevelDesc.cpp
src/level/View.cpp
src/level/Unit.cpp
src/level/StepDecor.cpp
src/level/StatusDisplay.cpp
src/level/ShapeBuilder.cpp
src/level/Shape.cpp
src/level/Rules.cpp
src/level/RopeDecor.cpp
src/level/RoomAccess.cpp
src/level/Room.cpp
src/level/PhaseLocker.cpp
src/level/MouseControl.cpp
src/level/ModelList.cpp
src/level/ModelFactory.cpp
src/level/MarkMask.cpp
src/level/LevelStatus.cpp
src/level/LevelScript.cpp
src/level/LevelLoading.cpp
src/level/LevelInput.cpp
src/level/LevelCountDown.cpp
src/level/Level.cpp
src/level/level-script.cpp
src/level/Landslip.cpp
src/level/KeyControl.cpp
src/level/Goal.cpp
src/level/game-script.cpp
src/level/FinderField.cpp
src/level/FinderAlg.cpp
src/level/Field.cpp
src/level/Dir.cpp
src/level/Cube.cpp
src/level/Controls.cpp
src/level/Anim.cpp
src/gengine/VideoAgent.cpp
src/gengine/TimerAgent.cpp
src/gengine/SysVideo.cpp
src/gengine/StringTool.cpp
src/gengine/StringMsg.cpp
src/gengine/SoundAgent.cpp
src/gengine/SDLSoundAgent.cpp
src/gengine/SDLMusicLooper.cpp
src/gengine/SDLException.cpp
src/gengine/ScriptState.cpp
src/gengine/Scripter.cpp
src/gengine/ScriptAgent.cpp
src/gengine/ResSoundPack.cpp
src/gengine/ResImagePack.cpp
src/gengine/ResDialogPack.cpp
src/gengine/Random.cpp
src/gengine/PlannedDialog.cpp
src/gengine/Path.cpp
src/gengine/options-script.cpp
src/gengine/OptionParams.cpp
src/gengine/OptionAgent.cpp
src/gengine/Name.cpp
src/gengine/MultiDrawer.cpp
src/gengine/MouseStroke.cpp
src/gengine/MixException.cpp
src/gengine/MessagerAgent.cpp
src/gengine/Log.cpp
src/gengine/KeyStroke.cpp
src/gengine/KeyBinder.cpp
src/gengine/IntMsg.cpp
src/gengine/InputHandler.cpp
src/gengine/InputAgent.cpp
src/gengine/ImgException.cpp
#src/gengine/FsPath_boost.cpp
src/gengine/FsPath.cpp
src/gengine/ExInfo.cpp
src/gengine/Environ.cpp
src/gengine/DialogStack.cpp
src/gengine/Dialog.cpp
src/gengine/def-script.cpp
src/gengine/BaseMsg.cpp
src/gengine/BaseListener.cpp
src/gengine/BaseException.cpp
src/gengine/BaseAgent.cpp
src/gengine/AgentPack.cpp
src/game/main.cpp
src/game/GameAgent.cpp
src/game/Application.cpp
src/effect/WavyPicture.cpp
src/effect/TTFException.cpp
src/effect/SurfaceTool.cpp
src/effect/SurfaceLock.cpp
src/effect/PixelTool.cpp
src/effect/PixelIterator.cpp
src/effect/Picture.cpp
src/effect/Outline.cpp
src/effect/LayeredPicture.cpp
src/effect/Font.cpp
src/effect/EffectZx.cpp
src/effect/EffectReverse.cpp
src/effect/EffectNone.cpp
src/effect/EffectMirror.cpp
src/effect/EffectDisintegrate.cpp
src/SDL_gfx/SDL_gfxPrimitives.c
)


#set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
#set(Boost_USE_STATIC_RUNTIME OFF) 

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-mixer CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem )

include_directories(${Boost_INCLUDE_DIRS}) 


target_link_libraries(fillets PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(fillets PRIVATE SDL2::SDL2_image)
target_link_libraries(fillets PRIVATE SDL2::SDL2_mixer)
target_link_libraries(fillets PRIVATE SDL2::SDL2_ttf)
target_link_libraries(fillets PRIVATE Boost::boost ${Boost_LIBRARIES})



target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/src/SDL_gfx/  
${CMAKE_CURRENT_SOURCE_DIR}/src/effect/  
${CMAKE_CURRENT_SOURCE_DIR}/src/game/  
${CMAKE_CURRENT_SOURCE_DIR}/src/gengine/  
${CMAKE_CURRENT_SOURCE_DIR}/src/level/  
${CMAKE_CURRENT_SOURCE_DIR}/src/menu/  
${CMAKE_CURRENT_SOURCE_DIR}/src/option/ 
${CMAKE_CURRENT_SOURCE_DIR}/src/plan/  
${CMAKE_CURRENT_SOURCE_DIR}/src/state/  
${CMAKE_CURRENT_SOURCE_DIR}/src/widget/
)


include(FindLua)
find_package(lua REQUIRED)
target_link_libraries(fillets PRIVATE ${LUA_LIBRARIES})
target_include_directories(fillets PRIVATE ${LUA_INCLUDE_DIR})



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_TOOLCHAIN_FILE "C:/Users/domin/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(DCMAKE_EXPORT_COMPILE_COMMANDS 1)

include(CPack)


