cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(PROJECT_NAME life)
set(TARGET main)


project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

file(GLOB source_files
	"src/*.cpp"
)

set(SOURCES ${source_files})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)

add_executable(${TARGET} ${SOURCES})
target_include_directories(${TARGET} PRIVATE "include")
target_link_libraries(${TARGET} sfml-system sfml-window sfml-graphics)



