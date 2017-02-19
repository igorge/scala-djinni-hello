cmake_minimum_required(VERSION 3.5)
project(hello_world_jni)
set(proj_exe_name hello_world_jni)

####-D CMAKE_CXX_COMPILER=/usr/bin/clang++
#set(CMAKE_VERBOSE_MAKEFILE ON)

#set(CMAKE_AR "gcc-ar")
#set(CMAKE_RANLIB "gcc-ranlib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wno-deprecated -Wno-unused-parameter")

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
#add_subdirectory(../../libgie/ ${PROJECT_BINARY_DIR}/extlib/gie )

#set(gie_include_dir ${gie_include_dir} ${libgie_SOURCE_DIR}/include)
#set(gie_link_libs ${gie_link_libs} libgie)

#set(gie_link_osg_libs osg osgDB osgViewer osgUtil)
############################################################################

find_package(JNI)

if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

############################################################################

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR} ${Boost_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR} ${JNI_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/support-lib/jni ${gie_include_dir} )

############################################################################


set(SOURCE_FILES
        main.cpp
        generated/jni/hello_world.cpp
        generated/jni/hello_world_maker.cpp
        support-lib/jni/djinni_main.cpp
        support-lib/jni/djinni_support.cpp)

############################################################################

add_library(${proj_exe_name} SHARED ${SOURCE_FILES})

target_link_libraries(
        ${proj_exe_name} )
