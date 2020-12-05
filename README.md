# InxaneUtils
This is a C++ library for my personal use, but I've decided to use GitHub for it, to not only practice it but share my code if anyone wants it.
# Linking
Add the project source to your include directiories and use the following line of code to include everything:

    #include "InxaneUtils.hpp"
Everything is in the `inx` namespace now. The library is not being compiled because it uses a lot of templates for ease of use, which is also why this library is header-only as well.
# inx::io
This module has a few utility functions to make printing to stdout a little less difficult, and a few other stuff.
### inx::io::print(), inx::io::printsep(), inx::io::println()
This is a set of classes (yes, classes but with overloaded `()` operators) that make printing easier. You probably want to use `inx::io::printsep` and `inx::io::println`. The first, `printsep`, prints what you pass to it, but separated by a space. This is something a bit boring to do with `iostream`, because you have to include the space yourself, but this doesn't force you to do that.

To use these functions you have to instantiate that class and use the `<<` operator, which you can chain.

    inx::io::printsep() << "Hello," << "World!" << 10 + 5;
    inx::io::println() << "Hello," << "World!" << 10 + 5;
### inx::io::input()
This is a templated function that makes taking input from the console a bit easier.
This is how you can quickly get an `int` from the user:

    int a = inx::io::input<int>();
The function returns the value it got. You can use it with any type that overloads the `>>` operator.
This function is overloaded for `std::string`, to get the whole line instead of one word, like `std::cin` does. Under the hood, it uses `std::getline()`.

When you use the function with nothing in the template (`void`), it waits for enter without returning any values. To avoid having to type `inx::io::input<void>()`, you can use another helper function, `inx::io::wait()`, which does the same thing, but with no template arguments.

# inx::data
This module has currently two custom data structures, a doubly-linked list, and a BST tree implementation.
### inx::data::LinkedList
You can simply instantiate it as any class, and use the `inx::data::LinkedList::add_node` function to add a new node (or `delete_node` to delete them)

    inx::data::LinkedList<int> list;
    list.add_node(5);
    list.add_node(15);
Under the hood, the nodes are `inx:data::LinkedListNode<T>` objects.
There are three more functions, `get_size()`, `get_head()`, and `get_tail()`.

- `get_size()` returns the amount of nodes in the list.
- `get_head()` returns the first element in the list.
- `get_tail()` return the last element in the list.

Empty elements are set as `nullptr`.
This is an example on how to iterate over this list:

    for (auto* cur = list.get_head(); cur != nullptr; cur = cur->next) {
	    inx::io::println() << cur->data;
    }
This prints out all the nodes in the list.
### inx::data::BSTNode
This is a simple templated implementation of a BST tree. There is no need for a BST class, I decided to only implement a single node, and that is enough.

Simple example:

    inx::data::BSTNode<int> tree;
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
     
    inx::data::BSTNode::print(&tree);
    
    inx::data::BSTNode<int>* result = inx::data::BSTNode::search(15, &tree);
Some of these functions are static, the reason why is because they use recursion.
### inx::data::Vote
This is my own data structue/utility structure called Vote. You have a list of elements, for example people, and you can vote for any of them.
You can access the person with the most and least amount of votes, or access the amount of votes for any indiviudual element.

Simple example:

    inx::data::Vote<std::string> vote({"Brian", "Jeffrey", "Anne"});
    vote.vote("Brian");
    vote.vote("Jeffrey");
    vote.vote("Jeffrey");
    inx::io::printsep() << vote.get_votes("Brian")
                        << vote.get_votes("Jeffrey")
                        << vote.get_votes("Anne")
                        << vote.top()
                        << vote.bottom();
    // Outputs 1 2 0 Jeffrey Anne
Under the hood, this implementation uses a simple std::unordered_map.
# inx::file
This is a module that provides some helper utilities when dealing with files.
### inx::file::ByteFileReader
This is a utility class for dealing with raw byte files.
You first instantiate it with any filename, and from there you can read a sequence of bytes at any index, automatically casting it into the correct datatype.
Imagine `file.bin` has one byte that's either 0 or 1, and after that, 4 bytes that represent an unsigned int. The following program will output that data:

    inx::file::ByteFileReader file("file.bin");
    inx::io::printsep() << file.get_value<bool>(0)
                        << file.get_value<int>(1);
    
You can also get the raw `byte*` array the program uses, by accessing `file.getRawData()`.
# inx::math
This is a module that provides some helper utilities for math.
### inx::math::linear_space
This function is an implementation of a linear space function. It returns an `std::vector` of `count` numbers evenly spaced out between `a` and `b`.

    std::vector<double> space = inx::math::linear_space<double>(1, 10, 9);
First parameter is the a, second is the b, and the third is the count, or n.
### inx::math::quadratic
This is a function that takes in `a`, `b`, and `c` from a quadratic equation, and returns a tuple with both of the results. The function returns `(0, 0)` if the value under the square root of the quadratic formula is negative (so it's complex).

    auto [a, b] = inx::math::quadratic<double>(1, 5, 6);
This saves both of the results into variables `a` and `b`, using structured binding.
### inx::math::factorial
This is a simple factorial function. Because of the nature of factorials, you should probably use the `uint64_t` type as the template argument, because it is the largest mostly supported data type.

    uint64_t result = inx::math::factorial<uint64_t>(20);
# inx::vec
This is a module that has helper functions for dealing with vectors.
### inx::vec::to_string()
This function turns a `std::vector` into a nicely formatted string in the Python style.

    std::vector<int> v = {1, 2, 3, 4};
    inx::io::println() << inx::math::to_string(v);
    // outputs [1, 2, 3, 4]
There are optional parameters which you can use to format it differently.
This is how the function declaration looks like, you can modify any of these parameters.

    std::string to_string(const std::vector<T>& vec, char start = '[', char end = ']', std::string separator = ", ")
# inx::string
This is a module that has helper functions for dealing with string.
### inx::string::reverse()
This function takes a string by reference and reverses it in-place.

    std::string cool_string = "Hello World!";
    inx::string::reverse(cool_string);
