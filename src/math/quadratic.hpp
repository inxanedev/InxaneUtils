#pragma once
#include <cmath>
#include <tuple>

namespace inx {
    namespace math {
        template <typename T>
    	std::tuple<T, T> quadratic(T a, T b, T c) {
			T under = pow(b, 2) - 4 * a * c;
			if (under < 0)
				return std::make_tuple<T, T>(0, 0);
			T surd = sqrt(under);
			T denom = 2 * a;
			return std::make_tuple<T, T>(
    			(-b + surd)/denom,
    			(-b - surd)/denom
    		);
    	}
    }
}