cmake_minimum_required(VERSION 3.20)
project(SFML_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")
set(RESOURCES_DEST "${CMAKE_BINARY_DIR}/resources")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp" 
    "src/*/*.cpp"
)
file(GLOB_RECURSE HEADERS 
    "include/*.hpp" 
    "include/*/*.hpp"
)

add_executable(game ${SOURCES} ${HEADERS})

target_include_directories(game
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"  # For cpp files
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"  # For external users
        ${SFML_INCLUDE_DIR}
)

target_link_libraries(game PRIVATE 
    SFML::Graphics 
    SFML::Window 
    SFML::System
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

file(COPY ${RESOURCES_DIR}/ DESTINATION ${RESOURCES_DEST})

if(APPLE)
    set_source_files_properties(${RESOURCES_DIR} PROPERTIES 
        MACOSX_PACKAGE_LOCATION Resources
    )
elseif(WIN32)
    add_custom_command(TARGET game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RESOURCES_DIR}
            $<TARGET_FILE_DIR:game>/resources
    )
endif()

# 8. Compile definitions for resource paths
target_compile_definitions(game PRIVATE
    RESOURCES_DIR="${RESOURCES_DEST}"
)

# 9. Optional: IDE source grouping
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include PREFIX "Headers" FILES ${HEADERS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src PREFIX "Sources" FILES ${SOURCES})

# 10. Install rules (for packaging)
install(TARGETS game DESTINATION bin)
install(DIRECTORY ${RESOURCES_DIR}/ DESTINATION resources)
