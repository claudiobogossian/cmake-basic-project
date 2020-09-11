cmake_minimum_required(VERSION 3.1...3.16)

project(
  CMakeBasicProjectLib
  VERSION 1.0
  LANGUAGES CXX)

find_package(CURL)

add_definitions( -DBOOST_ALL_NO_LIB )
add_definitions( -DBOOST_ALL_DYN_LINK )

find_package(Boost 1.53.0 REQUIRED system date_time chrono timer filesystem thread log log_setup locale regex
                          OPTIONAL_COMPONENTS python unit_test_framework ${BOOST_STACKTRACE_COMPONENTS} )

find_package(GDAL 2.1.3)

find_package(PROJ4)                          

include_directories(${GDAL_INCLUDE_DIR} ${PROJ4_INCLUDE_DIR} ${BOOST_INCLUDE_DIR} ${CURL_INCLUDE})

SET(CMAKE_INSTALL_RPATH "/home/bogo/workspace-terraamazon/terralib5-deps/dependencies/lib:${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/bin")

add_library(CMakeBasicProjectLib SHARED ../src/basiclib.cpp ../src/basiclib.h)

target_link_libraries(CMakeBasicProjectLib PUBLIC ${GDAL_LIBRARY_DEBUG} ${PROJ4_LIBRARY_DEBUG} ${BOOST_SYSTEM_LIBRARY} ${CURL_LIBRARY} )

project(
  CMakeBasicProjectMain
  VERSION 1.0
  LANGUAGES CXX)

SET(CMAKE_INSTALL_RPATH "/home/bogo/workspace-terraamazon/terralib5-deps/dependencies/lib:${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/bin")

add_executable(CMakeBasicProjectMain ../src/basicmain.cpp)

target_link_libraries(CMakeBasicProjectMain PUBLIC CMakeBasicProjectLib )

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Bogô")
set(CPACK_PACKAGE_EXECUTABLES "CMakeBasicProjectMain" "CMakeBasicProjectMain")

install(TARGETS CMakeBasicProjectLib DESTINATION lib)

install(TARGETS CMakeBasicProjectMain DESTINATION bin)

install(FILES ../src/basiclib.h DESTINATION include)

#FixBundle

configure_file(
     ${CMAKE_SOURCE_DIR}/FixBundle.cmake.in
     ${CMAKE_BINARY_DIR}/FixBundle.cmake
     @ONLY
)
install(SCRIPT ${CMAKE_BINARY_DIR}/FixBundle.cmake)

include(CPack)

