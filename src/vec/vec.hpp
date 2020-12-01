#pragma once
#include <vector>
#include <string>
#include <sstream>
namespace inx {
	namespace vec {
		template <typename T>
		std::string toString(const std::vector<T>& vec, char start = '[', char end = ']', std::string separator = ", ") {
			std::ostringstream result;
			result << start;
			for (size_t i = 0; i < vec.size(); i++) {
				result << vec[i];
				if (i != vec.size() - 1) result << separator;
			}
			result << end;
			return result.str();
		}
	};
}
