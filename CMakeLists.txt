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