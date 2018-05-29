#include <iostream>
using namespace std;
int main(){
    int a;
    int num;
    while(cin>>a){
        int mul = 1;
        for (int i = 0 ; i < a; i++){
            cin >> num;
            if (num %2 != 0){
                mul *= num;
            }
        }
        cout << mul << endl;
    }
}
