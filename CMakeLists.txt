# CMake version requried
cmake_minimum_required (VERSION 3.0)

#Project information
project (AlgorithmsInCpp)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/source/Include)

set(TEST_MAIN_FILE ${CMAKE_SOURCE_DIR}/source/Tests/testMain.cpp)

find_library(LIB_GMOCK gmock PATH ${CMAKE_SOURCE_DIR}/lib)
find_library(LIBRARY_GMOCK_MAIN gmock_main PATH ${CMAKE_SOURCE_DIR}/lib)
find_library(LIBRARY_GTEST gtest  PATH ${CMAKE_SOURCE_DIR}/lib)
find_library(LIBRARY_GTEST_MAIN gtest_main PATH ${CMAKE_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME}-UT_LIB OBJECT
	${CMAKE_SOURCE_DIR}/source/Static/ReverseNumber/ReverseNum.cpp
)

add_library(${PROJECT_NAME}-MAIN_UT_LIB OBJECT
    ${TEST_MAIN_FILE}
)

MESSAGE (${LIB_GMOCK})
MESSAGE (${LIBRARY_GMOCK_MAIN})
MESSAGE (${LIBRARY_GTEST})
MESSAGE (${LIBRARY_GTEST_MAIN})

add_executable(${PROJECT_NAME}-MAIN
    $<TARGET_OBJECTS:${PROJECT_NAME}-UT_LIB>
    $<TARGET_OBJECTS:${PROJECT_NAME}-MAIN_UT_LIB>
)

target_link_libraries(${PROJECT_NAME}-MAIN
    ${LIB_GMOCK}
    ${LIBRARY_GMOCK_MAIN}
    ${LIBRARY_GTEST}
    ${LIBRARY_GTEST_MAIN}
    pthread
)
