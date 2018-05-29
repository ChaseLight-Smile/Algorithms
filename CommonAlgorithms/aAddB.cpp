#include <iostream>
using namespace std;
void aAddB(){
    int m = 0;
    int n;
    while (cin >> m){
            int sum1;
            int sum2;
        for (int i = 0; i < m; i++){
            cin >> n;
            if (n >= 100){
                sum1 = n%10 + ((n /10)%10)*10;
            }else{
                sum1 = n;
            }
            cin >> n;
            if (n >= 100){
                sum2 = n%10 + ((n /10)%10)*10;
            }else{
                sum2 = n;
            }
            sum1+=sum2;
            if (sum1 >= 100){
                sum1 = sum1%10 + ((sum1 /10)%10)*10;
            }else{
                sum1 = sum1;
            }
            cout << sum1 << endl;
        }
    }
}

int main(){
  aAddB();
  return 0;
}
