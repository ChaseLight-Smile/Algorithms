#include <iostream>
#include <string>
using namespace std;

void HDU2017(){
    int count;
    while (cin >> count){
        string s;
        for (int i = 0; i < count; i++){
            cin >> s;
            int number = 0;
            const char *result = s.c_str();
            int size = s.length();
            for (int i = 0; i < size; i++){
                if (isdigit(result[i])){
                    number++;
                }
            }
            cout << number << endl;
        }
        break;
    }
}

int main(){
    HDU2017();
    return 0;
}
