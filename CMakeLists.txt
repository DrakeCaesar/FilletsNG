cmake_minimum_required(VERSION 3.12)
project(fillets VERSION 0.1.0)

include(ProcessorCount)
ProcessorCount(num_jobs)

if(num_jobs EQUAL 0)
    set(num_jobs 1)
endif()

message("Number of available processors: " ${num_jobs})

# Set the number of parallel jobs to use
set(CMAKE_BUILD_PARALLEL_LEVEL ${num_jobs})

include(CTest)
include(CPack)
enable_testing()

file(GLOB_RECURSE fillets_SRC CONFIGURE_DEPENDS "src/*.cpp")
list(FILTER fillets_SRC EXCLUDE REGEX ".*FsPath_boost\.cpp$")
add_executable(fillets ${fillets_SRC})

# Find Lua
find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})

if(UNIX)
    add_definitions(-DPLATFORM_UNIX)

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
    pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
    pkg_check_modules(SDL2_GFX REQUIRED SDL2_gfx)
    pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)

    target_include_directories(fillets PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
    target_include_directories(fillets PUBLIC ${SDL2_GFX_INCLUDE_DIRS})
    target_include_directories(fillets PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
    target_include_directories(fillets PUBLIC ${SDL2_MIXER_INCLUDE_DIRS})
    target_link_libraries(fillets ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_GFX_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${LUA_LIBRARIES})

    set(USE_LINUX_AUDIO_FORMAT 1)

elseif(WIN32)
    add_definitions(-DPLATFORM_WINDOWS)

    find_package(SDL2 CONFIG REQUIRED)
    find_package(sdl2-gfx CONFIG REQUIRED)
    find_package(SDL2_image CONFIG REQUIRED)
    find_package(SDL2_mixer CONFIG REQUIRED)
    find_package(SDL2_ttf CONFIG REQUIRED)

    target_link_libraries(fillets PRIVATE SDL2::SDL2_gfx)
    target_link_libraries(fillets PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
    target_link_libraries(fillets PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
    target_link_libraries(fillets PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)
    target_link_libraries(fillets PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)
    target_link_libraries(fillets PRIVATE ${LUA_LIBRARIES})

    set(USE_WINDOWS_AUDIO_FORMAT 1)
endif()

file(GLOB fillets_INCLUDE_DIRS LIST_DIRECTORIES true "src/*/")

foreach(dir ${fillets_INCLUDE_DIRS})
    target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${dir})
endforeach()

include(FindLua)
target_include_directories(fillets PRIVATE ${LUA_INCLUDE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(DCMAKE_EXPORT_COMPILE_COMMANDS 1)
