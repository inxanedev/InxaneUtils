#pragma once
#include <cmath>
#include <tuple>

namespace inx {
    namespace math {
        template <typename T>
    	std::tuple<T, T> quadratic(T a, T b, T c) {
    		T surd = sqrt(pow(b, 2) - 4 * a * c);
    		return std::make_tuple<T, T>(
    			(-b + surd)/(2 * a),
    			(-b - surd)/(2 * a)
    		);
    	}
    }
}