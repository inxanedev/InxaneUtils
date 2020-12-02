#pragma once
#include <vector>

namespace inx {
    namespace math {
		// this function is made so i don't have to copy code three times
        template <typename T>
    	void _linear_space_fill(std::vector<T>& vec, T a, T b, uint32_t count) {
    		vec.reserve(count);
    		T step = (b - a) / count;
    		for (T i = a; i <= b; i += step) {
    			vec.push_back(i);
    		}
    	}
        template <typename T>
    	std::vector<T> linear_space(T a, T b, uint32_t count) {
    		std::vector<T> vec;
    		_linear_space_fill<T>(vec, a, b, count);
    		return vec;
    	}
    	template <typename T>
    	void linear_space(std::vector<T>& vec, T a, T b, uint32_t count) {
    		_linear_space_fill<T>(vec, a, b, count);
    	}
    }
}