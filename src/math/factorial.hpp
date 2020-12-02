#pragma once
#include <cmath>
namespace inx {
    namespace math {
        template <typename T = uint64_t>
        T factorial(T value) {
            T result = 1;
            for (T i = 1; i <= value; i++)
                result *= i;
            return result;
        }
    }
}