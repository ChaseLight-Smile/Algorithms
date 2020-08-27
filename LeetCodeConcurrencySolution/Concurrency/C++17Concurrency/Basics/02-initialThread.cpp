// 编译命令 g++ initialThread -o test -pthread -std=c++17
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

void func(string s){
    cout << s << endl;
}

class Base{
    public:
        void operator()(string s){
            cout << s << endl;
        }
};

class BaseNonStatic{
    public:
        void test(string s){
            cout << s << endl;
        }
};

class BaseStatic{
    public:
        static void test(string s){
            cout << s << endl;
        }
};

int main(){
    auto startTime = high_resolution_clock::now();
    std::thread t1(func, "This is first method uses function pointer~");
    std::thread t2([](string s){
            cout << s << endl;
            }, "This is second method uses lambda expression~");
    std::thread t3((Base()), "This is third method uses functor~");
    
    BaseNonStatic b;
    std::thread t4(&BaseNonStatic::test, b, "This is forth method uses non static function in class~");
    std::thread t5(&BaseStatic::test, "This is fifth method uses static function in class~");


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    auto endTime = high_resolution_clock::now();
    auto durationTime = duration_cast<microseconds>(endTime-startTime);
    cout << "Second: " << durationTime.count()/1000000 << endl; 
    return 0;
}
