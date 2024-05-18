#include <iostream>  
#include <new>  

// 用户定义的 new_handler 函数  
void out_of_memory() {
    std::cerr << "Memory allocation failed! Exiting the program." << std::endl;
    std::abort();  // 终止程序  
}

int main() {
    // 设置 new_handler  
    //std::set_new_handler(out_of_memory);

    try {
        // 尝试分配大量内存，导致分配失败  
        int* large_array = new int[10000000000ull];
    }
    catch (const std::bad_alloc& e) {
        // 如果 new 抛出 bad_alloc 异常，捕获它  
        std::cerr << "Caught bad_alloc: " << e.what() << std::endl;
    }

    return 0;
}