#include <iostream>
using namespace std;

void HDU2013(){
    int day;
    while(cin >> day){
        int sum = 1 ;
        int current = 1;
        for (int i = day; i > 1; i--){
            sum = current;
            current = 2 * current + 1;
        }
        cout << sum+current << endl;
    }
}

int main(){
    HDU2013();
    return 0;
}
