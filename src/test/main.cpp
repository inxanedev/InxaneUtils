#include "InxaneUtils/InxaneUtils.hpp"

int main() {
    inx::io::println() << "Hello World!";
    int test = inx::io::input<int>();
    inx::io::println() << test;
    inx::io::end();
}
