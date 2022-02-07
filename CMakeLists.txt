cmake_minimum_required(VERSION 3.12)
project(fillets VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE fillets_SRC CONFIGURE_DEPENDS 
     "src/*.cpp"
)
list(FILTER fillets_SRC EXCLUDE REGEX ".*FsPath_boost\\.cpp$")


add_executable(fillets ${fillets_SRC})

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-mixer CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)

target_link_libraries(fillets PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(fillets PRIVATE SDL2::SDL2_image)
target_link_libraries(fillets PRIVATE SDL2::SDL2_mixer)
target_link_libraries(fillets PRIVATE SDL2::SDL2_ttf) 
target_link_libraries(fillets PRIVATE SDL2::SDL2_gfx)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE 
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
target_link_libraries(fillets PRIVATE ${LUA_LIBRARIES})
target_include_directories(fillets PRIVATE ${LUA_INCLUDE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(DCMAKE_EXPORT_COMPILE_COMMANDS 1)

include(CPack)




