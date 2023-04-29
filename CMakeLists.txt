cmake_minimum_required(VERSION 3.12)
project(fillets VERSION 0.1.0)

include(CTest)
include(CPack)
enable_testing()

file(GLOB_RECURSE fillets_SRC CONFIGURE_DEPENDS "src/*.cpp")
list(FILTER fillets_SRC EXCLUDE REGEX ".*FsPath_boost\.cpp$")
add_executable(fillets ${fillets_SRC})

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_link_libraries(fillets PRIVATE
    SDL2::SDL2_gfx)
target_link_libraries(fillets PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
target_link_libraries(fillets PRIVATE
    $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
target_link_libraries(fillets PRIVATE
    $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)
target_link_libraries(fillets PRIVATE
    $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

file(GLOB fillets_INCLUDE_DIRS LIST_DIRECTORIES true "src/*/")

foreach(dir ${fillets_INCLUDE_DIRS})
    target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${dir})
endforeach()

include(FindLua)
target_link_libraries(fillets PRIVATE ${LUA_LIBRARIES})
target_include_directories(fillets PRIVATE ${LUA_INCLUDE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(DCMAKE_EXPORT_COMPILE_COMMANDS 1)
