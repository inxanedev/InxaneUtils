#pragma once
#include <string>
#include <algorithm>
namespace inx {
    namespace string {
        void reverse(std::string& str) {
            std::reverse(str.begin(), str.end());
        }
    }
}
