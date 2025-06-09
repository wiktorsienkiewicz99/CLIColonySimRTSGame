cmake_minimum_required(VERSION 3.31)
project(RTS_ColonySim)

# Force correct libc++ linkage
if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++ -lc++abi")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(RTS_ColonySim src/main.cpp
        src/Entity/Entity.cpp
        src/Entity/Entity.h
        src/Entity/Units/Unit.cpp
        src/Entity/Units/Unit.h
        src/Entity/Buildings/Building.cpp
        src/Entity/Buildings/Building.h
        src/Core/CommandSystem/CommandProcessor/CommandProcessor.cpp
        src/Core/CommandSystem/CommandProcessor/CommandProcessor.h
        src/Core/GameLoop.cpp
        src/Core/GameLoop.h
        src/Map/World.cpp
        src/Map/World.h
        src/Core/CommandSystem/Command/Command.cpp
        src/Core/CommandSystem/Command/Command.h
        src/Core/CommandSystem/CommandRegistry/CommandRegistry.cpp
        src/Core/CommandSystem/CommandRegistry/CommandRegistry.h
        src/Core/CommandSystem/CommandsList/CommandsList.cpp
        src/Core/CommandSystem/CommandsList/CommandsList.h
        src/Core/Coordinates/Position2D.h
        src/UI/ConsoleUI.cpp
        src/UI/ConsoleUI.h)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(RTS_ColonySim ${CURSES_LIBRARIES})