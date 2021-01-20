# CMakeList.txt : CMake project for KLInterface_so, include source and define
# project specific logic here.
#
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv7)

# root path for toolchains
set(toolchainpath C:/build/18.0/arm/sysroots)

# compilers
set(CMAKE_C_COMPILER ${toolchainpath}/i686-nilrtsdk-mingw32/usr/bin/arm-nilrt-linux-gnueabi/arm-nilrt-linux-gnueabi-gcc.exe)
set(CMAKE_CXX_COMPILER ${toolchainpath}/i686-nilrtsdk-mingw32/usr/bin/arm-nilrt-linux-gnueabi/arm-nilrt-linux-gnueabi-g++.exe)

# compiler flags
set(CMAKE_SYSROOT ${toolchainpath}/cortexa9-vfpv3-nilrt-linux-gnueabi)
SET(CMAKE_<LANG>_STANDARD_INCLUDE_DIRECTORIES ${toolchainpath}/cortexa9-vfpv3-nilrt-linux-gnueabi/usr/include/c++/6.3.0 
${toolchainpath}/cortexa9-vfpv3-nilrt-linux-gnueabi/usr/include/c++/6.3.0/arm-nilrt-linux-gnueabi)
set(CMAKE_<LANG>_FLAGS "-Wall -fmessage-length=0 -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_<LANG>_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_<LANG>_FLAGS_RELEASE "-O3")

# define search behavior
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.14)

project(KLInterface_so)

add_library(KLInterface SHARED ../shared/KLInterface.cpp ../shared/KLInterface.h)

target_include_directories(KLInterface PRIVATE C:/Program\ Files\ \(x86\)/National\ Instruments/LabVIEW\ 2019/cintools)

