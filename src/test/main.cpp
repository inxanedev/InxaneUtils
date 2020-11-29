#include "InxaneUtils/InxaneUtils.hpp"

#include <vector>
#include <string>
int main() {
    inx::data::BSTNode<int> node(10);
    node.insert(5);
    node.insert(15);

    inx::data::BSTNode<int>::print(&node);        

    inx::data::BSTNode<int>* result = inx::data::BSTNode<int>::search(15, &node);
    inx::data::BSTNode<int>* result2 = inx::data::BSTNode<int>::search(16, &node);

    inx::io::printsep() << result << result2;

    inx::io::newline();
}
