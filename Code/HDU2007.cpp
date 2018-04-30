#include <iostream>
using namespace std;
int main(){
    int a;
    int b;
    while(cin >> a){
        int sum1 = 0;
        int sum2= 0;
        cin >> b;
        for (int i = a ; i <= b ; i++){
            if (i % 2 == 0){
                sum1 += i*i;
            }else{
                sum2 += i * i * i;
            }
        }
        cout << sum1 << " " << sum2 << " "<< endl;
    } 
    return 0;
}
