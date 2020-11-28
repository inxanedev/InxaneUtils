#pragma once
#include <iostream>
#include <string>
namespace inx {
    namespace io {
        class print {
            public:
                template <typename T>
                print operator <<(const T& msg) {
                    std::cout << msg;
                    return *this;
                }
        };
        class println {
           public:
               template <typename T>
               println operator <<(const T& msg) {
                   std::cout << msg << std::endl;
                   return *this;
               }
        };
        class printsep {
            public:
                template <typename T>
                printsep operator <<(const T& msg) {
                    std::cout << msg << " ";
                    return *this;
                }
        };
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
		void newline() {
			std::cout << std::endl;
		}
		void end() {
			newline();
			wait();
		}
    }
}
