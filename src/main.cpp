#include <iostream>
#include "hello.hpp"

#define PROJECT_NAME "ebpf_decoder"

int main(int argc, char **argv) {
    if(argc != 1) {
        std::cout << argv[0] <<  "takes no arguments.\n";
        return 1;
    }
    std::cout << "This is project " << PROJECT_NAME << ".\n";
    hello();
    return 0;
}
