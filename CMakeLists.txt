cmake_minimum_required( VERSION 3.0 )
project( game )

set( CURSES_HAVE_NCURSES_H TRUE )
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )

list( APPEND GAME_HEADERS "src/headers" )

#headers
list( APPEND GAME_SOURCES "src/headers/cmain.h" )
list( APPEND GAME_SOURCES "src/headers/object.h" )
list( APPEND GAME_SOURCES "src/headers/player.h" )
list( APPEND GAME_SOURCES "src/headers/enemy.h" )
list( APPEND GAME_SOURCES "src/headers/factory_enemy.h" )
list( APPEND GAME_SOURCES "src/headers/healthbar.h" )
list( APPEND GAME_SOURCES "src/headers/scorebar.h" )

#sources
list( APPEND GAME_SOURCES "src/sources/cmain.cpp" )
list( APPEND GAME_SOURCES "src/sources/object.cpp" )
list( APPEND GAME_SOURCES "src/sources/player.cpp" )
list( APPEND GAME_SOURCES "src/sources/enemy.cpp" )
list( APPEND GAME_SOURCES "src/sources/factory_enemy.cpp" )
list( APPEND GAME_SOURCES "src/sources/healthbar.cpp" )
list( APPEND GAME_SOURCES "src/sources/scorebar.cpp" )
list( APPEND GAME_SOURCES "src/main.cpp" )

include_directories( ${GAME_HEADERS} )

add_executable( game ${GAME_SOURCES} )

target_link_libraries( game ${CURSES_LIBRARIES} )
