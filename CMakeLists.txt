cmake_minimum_required( VERSION 3.0 )
project( game )

set( CURSES_HAVE_NCURSES_H TRUE )
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )

list( APPEND GAME_HEADERS "src/headers" )

list( APPEND GAME_SOURCES "src/headers/cmain.h" )
list( APPEND GAME_SOURCES "src/headers/object.h" )
list( APPEND GAME_SOURCES "src/headers/player.h" )
list( APPEND GAME_SOURCES "src/headers/charge.h" )
list( APPEND GAME_SOURCES "src/sources/cmain.cpp" )
list( APPEND GAME_SOURCES "src/sources/object.cpp" )
list( APPEND GAME_SOURCES "src/sources/player.cpp" )
list( APPEND GAME_SOURCES "src/sources/charge.cpp" )
list( APPEND GAME_SOURCES "src/main.cpp" )

include_directories( ${GAME_HEADERS} )

add_executable( game ${GAME_SOURCES} )

target_link_libraries( game ${CURSES_LIBRARIES} )
