#include "InxaneUtils/InxaneUtils.hpp"

#include <vector>
#include <string>
int main() {
    inx::data::LinkedList<int> list;

    list.add_node(10);
    list.add_node(15);
    list.add_node(17);
    list.add_node(124);
    list.add_node(432);

    for (inx::data::LinkedListNode<int>* node = list.get_head(); node != nullptr; node = node->next) {
        inx::io::println() << node->data;
    }
}
