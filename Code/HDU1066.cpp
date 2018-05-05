#include <iostream>
using namespace std;
void HDU1066(){
    int n;
    while(cin >> n){
        int m;
        int p;
        int mul = 1;
        for (int i = 1; i <= n; i++){
            while(i > 0){
                m = i % 10;
                if (m != 0){
                    break;
                }else{
                    i = i / 10;
                }
            }
            while (mul > 0){
                p = mul % 10;
                if (p !=0 ){
                    break;
                }else{
                    mul = mul / 10;
                }
            }
            mul = p * m;
            while (mul > 0){
                p = mul % 10;
                if (p !=0 ){
                    break;
                }else{
                    mul = mul / 10;
                }
            }
            mul = p;
        }
        cout << mul << endl;
    }
}
int main(){
    HDU1066();
    return 0;
}
