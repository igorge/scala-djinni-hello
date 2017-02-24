cmake_minimum_required(VERSION 3.5)
project(hello_world_jni)
set(proj_exe_name hello_world_jni)

####-D CMAKE_CXX_COMPILER=/usr/bin/clang++
#set(CMAKE_VERBOSE_MAKEFILE ON)

#set(CMAKE_AR "gcc-ar")
#set(CMAKE_RANLIB "gcc-ranlib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wno-deprecated -Wno-unused-parameter -fPIC")

#find_package(Boost COMPONENTS filesystem system thread program_options serialization date_time locale)
############################################################################

#add_definitions(-D_FILE_OFFSET_BITS=64)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("*** Debug build. ***")
    ##add_definitions(-D_GLIBCXX_DEBUG)
    add_definitions(-DBOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
    add_definitions(-DBOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvtable-verify=std")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=float-cast-overflow")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-sanitize-recover")
else()
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finline-functions -findirect-inlining")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto")
endif ()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++1z-extensions")
############################################################################
set(DJINNI_MODULE ../../../modules/djinni_jni)

add_subdirectory(${DJINNI_MODULE} ${PROJECT_BINARY_DIR}/modules/djinni_jni)
############################################################################

get_directory_property(
        DJINNI_INCLUDE_DIRS
        DIRECTORY ${DJINNI_MODULE}
        DEFINITION DJINNI_INCLUDE_DIRS)

#message (STATUS "djinni_jni_SOURCE_DIR=${djinni_jni_SOURCE_DIR}")
#message (STATUS "DJINNI_INCLUDE_DIRS=${DJINNI_INCLUDE_DIRS}")


include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}
        ${DJINNI_INCLUDE_DIRS}
)

############################################################################

set(SOURCE_FILES
        main.cpp
        generated/jni/hello_world.cpp
        generated/jni/hello_world_maker.cpp
        ${djinni_jni_SOURCE_DIR}/src/support-lib/jni/djinni_main.cpp)

############################################################################

add_library(${proj_exe_name} SHARED ${SOURCE_FILES})

target_link_libraries(${proj_exe_name} djinni_jni)
