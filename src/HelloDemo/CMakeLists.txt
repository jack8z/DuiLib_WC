SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src/HelloDemo SRC_LIST)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/src/DuiLib")

LINK_DIRECTORIES("${PROJECT_BINARY_DIR}/lib")

SET(VC_RES small.ico HelloDemo.ico HelloDemo.rc)

IF(WIN32)
    SET(CMAKE_CXX_STANDARD 11)
	SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -SUBSYSTEM:WINDOWS")
    MESSAGE(STATUS "CMAKE_EXE_LINKER_FLAGS:" ${CMAKE_EXE_LINKER_FLAGS})
ENDIF(WIN32)

ADD_DEFINITIONS(-D_UNICODE -DUNICODE)

ADD_EXECUTABLE(HelloDemo WIN32 ${VC_RES} ${SRC_LIST})

TARGET_LINK_LIBRARIES(HelloDemo duilib)
