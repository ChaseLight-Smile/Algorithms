#include <iostream>
using namespace std;
bool isPrimer(int x){
    for (int j = 2; j < x ; j++){
        if (x % j == 0){
            return false;
        }else{
            continue;
        }
    }
    return true;
}

int main(){
    int x;
    while (cin >> x){
        int y;
        cin >> y;
        if (x==0 && y ==0){
            break;
        }
        int sum = 0 ;
        int a;
        for (int i = x; i <= y ; i++){
            a = i*i + i + 41;
            if (isPrimer(a)){
                sum += 1;
            }
        }
        if (sum == (y-x+1)){
            cout << "OK" << endl;
        }else{
            cout << "Sorry" << endl;
        }
    }
    return 0;
}
