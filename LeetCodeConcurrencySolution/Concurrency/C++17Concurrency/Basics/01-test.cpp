// 使用g++ 9.2.0 编译，g++ test.cpp -o test -pthread -std=c++17
#include <iostream>
#include <thread>
#include <filesystem>

void hello(){
    std::cout << "hello, C++ 17!" << std::endl;
}

int main(){
    std::thread t(hello);
    t.join();
    if(int a = 5; a < 8){
        std::cout << "Local variable a is < 8\n";
    }else{
        std::cout << "Local variable a is >= 8\n";
    }
    for(auto &file: std::filesystem::recursive_directory_iterator("./")){
		std::cout << file.path() << std::endl;
    }
    return 0;
}
