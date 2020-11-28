#include "InxaneUtils/InxaneUtils.hpp"

#include <vector>
#include <string>
int main() {
    inx::io::println() << "Hello World!";
    int test = inx::io::input<int>();
    inx::io::println() << test;
    
    std::vector<int> v = {1, 2, 3, 4};
    inx::io::println() << inx::vec::toString(v);
}
