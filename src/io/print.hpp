#pragma once
#include <iostream>
namespace inx {
    namespace io {
        template <typename T>
        void printsep(T t) { std::cout << t << std::endl; }

        template <typename T, typename... Rest>
        void printsep(T t, Rest... rest) {
            std::cout << t << ' ';
            printsep(rest...);
        }

        template <typename T>
        void print(T t) { std::cout << t << std::endl; }

        template <typename T, typename... Rest>
        void print(T t, Rest... rest) {
            std::cout << t << std::endl;
            print(rest...);
        }

        void newline() {
            std::cout << std::endl;
        }
        void flush() {
            std::cout.flush();
        }
    }
}
