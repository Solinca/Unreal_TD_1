cmake_minimum_required (VERSION 3.8)

cmake_policy(SET CMP0091 NEW)

project (CMakeProject1)

add_executable(CMakeProject1 src/main.cpp)

set(CPM_DOWNLOAD_VERSION 0.42.0)

include(CPM.cmake/cmake/CPM.cmake)

target_include_directories(CMakeProject1 PRIVATE include)

list(APPEND CMAKE_MODULE_PATH out/build/_deps/catch2-src/extras)

CPMAddPackage(
	NAME Catch2
	GITHUB_REPOSITORY CatchOrg/Catch2
	VERSION 3.6.0
	OPTIONS "CATCH_BUILD_TESTING OFF"
)

target_link_libraries(CMakeProject1 PRIVATE Catch2)

enable_testing()

add_executable(CMakeProjectTest tests/main.cpp)

target_link_libraries(CMakeProjectTest PRIVATE Catch2::Catch2WithMain)

include(Catch)

catch_discover_tests(CMakeProjectTest)

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
endif()
