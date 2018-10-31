cmake_minimum_required( VERSION 3.0 )
project( game )

set( CURSES_HAVE_NCURSES_H TRUE )
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )

list( APPEND GAME_SOURCES "src/cmain.h" )
list( APPEND GAME_SOURCES "src/main.cpp" )

add_executable( game ${GAME_SOURCES} )

target_link_libraries( game ${CURSES_LIBRARIES} )
