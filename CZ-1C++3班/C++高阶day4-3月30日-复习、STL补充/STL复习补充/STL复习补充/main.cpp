#include <iostream>  
#include <new>  

// �û������ new_handler ����  
void out_of_memory() {
    std::cerr << "Memory allocation failed! Exiting the program." << std::endl;
    std::abort();  // ��ֹ����  
}

int main() {
    // ���� new_handler  
    //std::set_new_handler(out_of_memory);

    try {
        // ���Է�������ڴ棬���·���ʧ��  
        int* large_array = new int[10000000000ull];
    }
    catch (const std::bad_alloc& e) {
        // ��� new �׳� bad_alloc �쳣��������  
        std::cerr << "Caught bad_alloc: " << e.what() << std::endl;
    }

    return 0;
}