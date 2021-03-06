# InxaneUtils
This is a C++ library for my personal use, but I've decided to use GitHub for it, to not only practice it but share my code if anyone wants it.
# Linking
Add the project source to your include directiories and use the following line of code to include everything:

    #include "InxaneUtils.hpp"
Everything is in the `inx` namespace now. The library is not being compiled because it uses a lot of templates for ease of use, which is also why this library is header-only as well.
# inx::io
This module has a few utility functions to make printing to stdout a little less difficult, and a few other stuff.
### inx::io::print(), inx::io::printsep()
These are functions that take in any amount of parameters and they print the arguments in different ways.  
The `inx::io::print()` function prints all of its argument on different lines, and the `inx::io::printsep()` function prints them all separated with a space, with a newline at the end.

    inx::io::print("Hello", "world", 5);
    inx::io::printsep(1, 2, 3.0);

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
    inx::io::println() << inx::vec::to_string(v);
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
# inx::shell
This is a module that provides helper functions for dealing with shell commands.
### inx::shell::read_stdout()
This function takes in a command, captures its stdout and returns an std::string with the output.

    std::string files = inx::shell::read_stdout("ls .");
    std::cout << files << std::endl;
    // outputs the list of files in the current directory
# inx::benchmarking
This is a module which provides useful timers and functions to benchmark C++ code internally.
### inx::benchmarking::BasicTimer
This is the implementation of the most basic timer, which has a start() and stop() function.  
The stop function by default prints the result in a nice formatted way to stdout, however you can specify an output variable of type `inx::benchmarking::duration` by reference to store the result there instead.  
This class has a template argument which represents the measurement format. By default, it's set to milliseconds, however you can choose microseconds as well, which are more precise.

    // Simple example of timing some code
    using namespace inx::benchmarking;
    BasicTimer<time_format::MICROSECONDS> timer;
    timer.start(); // starts the timer

    // Some code which takes some time to complete
    for (int i = 0; i < 10000; i++) {
        std::cout << i << std::endl;
    }

    timer.stop(); // Prints the result to stdout

To store the result in a duration variable instead of printing to stdout, you can do this:

    duration dur;
    timer.stop(dur);
    // dur now contains the measured time.

Note: `inx::benchmarking::duration` is simply an alias for `uint64_t`, so you should be fine with storing microseconds in this type, it will be big enough.
### inx::benchmarking::ScopeTimer
This is a timer which measures an entire scope, from start to finish.  
To use it, simply allocate the timer on the stack in a scope. It will start automatically, and stop automatically when the scope ends. By default it prints to stdout like the BasicTimer, and you can also pass in an output variable to the constructor.  
However, the output variable syntax is a bit different because you don't call `timer.stop()` explicitly. To deal with that, instead of passing the output variable as a reference, you pass a pointer to `inx::benchmarking::duration` in the constructor. By default it will have the value of `nullptr`, so that gets handled automatically.  
If you provided an output variable it will automatically set that variable.

    using namespace inx::benchmarking;
    void cool_function() {
        ScopeTimer timer;
        for (int i = 0; i < 10000; i++) {
            std::cout << i << std::endl;
        }
    }

    // when you call the function the timer will be started automatically now
    cool_function();
### inx::benchmarking::TimeFunction()
This function accepts any lambda, and times the execution of that lambda. It automatically prints the measured time by default, and you can specify an output variable as the second argument.  
To keep the code simple, it only accepts lambdas, but you can measure the execution of a regular non-lambda function by simply calling the function in the lambda.

    inx::benchmarking::TimeFunction([]() {
        for (int i = 0; i < 10000; i++) {
            std::cout << i << std::endl;
        }
    });
    // Prints the time it took to complete the execution of the lambda
### inx::benchmarking::time_format_cast()
If you'd like to cast between millisecond and microsecond durations, you can use this function.  
For example, if you measured the time in microseconds and you want to now cast the duration to milliseconds instead:

    using namespace inx::benchmarking;
    // here dur is a `inx::benchmarking::duration` which was measured with microseconds
    std::cout << time_format_cast<time_format::MILLISECONDS>(dur) << std::endl;
    // this line prints the converted duration from us to ms.
