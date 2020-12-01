#pragma once
#include <iostream>
namespace inx {
    namespace io {
        char endl = '\n';
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
        void newline() {
			std::cout << std::endl;
		}
        void flush() {
            std::cout.flush();
        }
    }
}