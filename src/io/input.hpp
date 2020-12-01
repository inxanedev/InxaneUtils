#pragma once
#include <string>
#include <iostream>
namespace inx {
    namespace io {
        template <typename T>
		T input() {
			T result;
			std::cin >> result;
			std::cin.ignore();
			return result;
		}
		template <>
		std::string input<std::string>() {
			std::string result;
			std::getline(std::cin, result);
			return result;
		}

		template <typename T>
		void input(T& var) {
			std::cin >> var;
			std::cin.ignore();
		}

		template <>
		void input(std::string& var) {
			std::getline(std::cin, var);
		}

		template <>
		void input(void) {
			std::cin.get();
		}

		void wait() {
			input<void>();
		}
    }
}