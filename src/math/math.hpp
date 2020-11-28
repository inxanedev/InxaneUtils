#include <vector>
#include <cmath>
namespace inx {
    namespace math {
    	template <typename T>
    	void _linearSpaceFill(std::vector<T>& vec, T a, T b, uint32_t count) {
    		vec.reserve(count);
    		T step = (b - a) / count;
    		for (T i = a; i <= b; i += step) {
    			vec.push_back(i);
    		}
    	}
        template <typename T>
    	std::vector<T> linearSpace(T a, T b, uint32_t count) {
    		std::vector<T> vec;
    		_linearSpaceFill<T>(vec, a, b, count);
    		return vec;
    	}
    	template <typename T>
    	void linearSpace(std::vector<T>& vec, T a, T b, uint32_t count) {
    		_linearSpaceFill<T>(vec, a, b, count);
    	}
    	template <typename T>
    	class QuadraticResult {
    		public:
    			T a, b;
    			QuadraticResult(T negative, T positive) {
    				a = negative;
    				b = positive;
    			}
    	};
    	template <typename T>
    	QuadraticResult<T> quadratic(T a, T b, T c) {
    		T surd = sqrt(pow(b, 2) - 4 * a * c);
    		return inx::math::QuadraticResult<T>(
    			-b + surd,
    			-b - surd
    		);
    	}	
    }
}
