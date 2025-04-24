//
//  main.cpp
//  LearnVulkan
//
//  Created by Michael Bui on 4/24/25.
//

#include <vulkan/vulkan.h>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <ostream>

class HelloTriangleApplication {
public:
    void run() {
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initVulkan() {

    }

    void mainLoop() {

    }

    void cleanup() {

    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}