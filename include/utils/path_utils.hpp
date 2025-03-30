#pragma once

#include <string>

namespace Resource {
    inline std::string resources(const std::string& relativePath) {
        #ifdef CMAKE_BUILD
            return std::string(RESOURCES_DIR) + "/" + relativePath;
        #else
            // Fallback for development
            return "../resources/" + relativePath;
        #endif
    }
}
