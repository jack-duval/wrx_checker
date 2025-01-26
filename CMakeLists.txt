cmake_minimum_required(VERSION 3.27)
project(wrx_checker)

set(CMAKE_CXX_STANDARD 23)

# Specify the directory containing the .proto files
set(PROTO_DIR ${CMAKE_SOURCE_DIR}/protos)

# Use file(GLOB ...) to gather all .proto files in the directory
file(GLOB PROTO_FILES ${PROTO_DIR}/*.proto)

# Check if .proto files are found
if(NOT PROTO_FILES)
    message(FATAL_ERROR "No .proto files found in ${PROTO_DIR}")
endif()

# Find the Protobuf and SQLite3 packages
find_package(Protobuf REQUIRED)
find_package(SQLite3 REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})

# Generate C++ source and header files from the .proto files
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# Add the generated protobuf files to your project as a library
add_library(proto_files ${PROTO_SRCS} ${PROTO_HDRS})

# Ensure the include directory is set correctly for the generated files
target_include_directories(proto_files PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Add executable
add_executable(wrx_checker src/main.cpp
        src/events/TestEvent.cpp
        src/events/TestEvent.h
        src/events/Event.h
        src/faults/Fault.cpp
        src/faults/Fault.h
        src/faults/Severity.h
        src/events/Event.cpp
        src/events/EventTypes.h
        src/events/ACCompressorStatusChange.h
        src/DBManager.cpp
        src/DBManager.h
        src/FaultReporter.cpp
        src/FaultReporter.h
        src/events/EventContext.cpp
        src/events/EventContext.h
        src/events/ACCompressorStatusChange.cpp
        src/CSVParser.cpp
        src/CSVParser.h
        src/RowContext.h
)

# Link the generated protobuf library and SQLite to your executable
target_link_libraries(wrx_checker proto_files ${Protobuf_LIBRARIES} sqlite3)