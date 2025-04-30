cmake_minimum_required(VERSION 3.15)
project(LearnVulkan)

set(CMAKE_CXX_STANDARD 20)

# Add source files
file(GLOB_RECURSE SOURCES "LearnVulkan/*.cpp" "LearnVulkan/*.h")

add_executable(LearnVulkan ${SOURCES})

# Find required packages
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)

# Set include directories
target_include_directories(${PROJECT_NAME} PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        ${Vulkan_LIBRARIES}
)

# Add shader compilation to CMake
find_program(GLSLC_EXECUTABLE NAMES glslc HINTS "$ENV{VULKAN_SDK}/bin")

if(NOT GLSLC_EXECUTABLE)
    message(FATAL_ERROR "glslc compiler not found")
endif()

set(SHADER_SOURCE_DIR "${CMAKE_SOURCE_DIR}/LearnVulkan/Shaders")
set(SHADER_BINARY_DIR "${CMAKE_BINARY_DIR}/shaders")

file(MAKE_DIRECTORY ${SHADER_BINARY_DIR})

# Compile vertex shader
add_custom_command(
        OUTPUT ${SHADER_BINARY_DIR}/vert.spv
        COMMAND ${GLSLC_EXECUTABLE} ${SHADER_SOURCE_DIR}/shader.vert -o ${SHADER_BINARY_DIR}/vert.spv
        DEPENDS ${SHADER_SOURCE_DIR}/shader.vert
        COMMENT "Compiling vertex shader"
)

# Compile fragment shader
add_custom_command(
        OUTPUT ${SHADER_BINARY_DIR}/frag.spv
        COMMAND ${GLSLC_EXECUTABLE} ${SHADER_SOURCE_DIR}/shader.frag -o ${SHADER_BINARY_DIR}/frag.spv
        DEPENDS ${SHADER_SOURCE_DIR}/shader.frag
        COMMENT "Compiling fragment shader"
)

# Create custom target for shaders
add_custom_target(shaders
        DEPENDS ${SHADER_BINARY_DIR}/vert.spv ${SHADER_BINARY_DIR}/frag.spv
)

# Make the main target depend on the shaders
add_dependencies(LearnVulkan shaders)