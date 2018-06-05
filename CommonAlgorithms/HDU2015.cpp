#include <iostream>
using namespace std;

void HDU2015(){
    int n;
    while(cin>>n){
        int m;
        cin >> m;
        int sum = 0;
        int start = 2;
        int count = 0;
        while(start <= 2*n){
            count++;
            if (count < m && start == 2*n){
                sum += start;
                cout << sum/count << endl;
                sum = 0;
                count = 0;
                start = start + 2;
                break;
            }
            if ((count == m)){
                sum += start;
                cout << sum/count << " ";
                sum = 0;
                count = 0;
                start = start + 2;
                continue;
            }else{
                sum += start;
                start += 2;
            }
        }
    }
}


int main(){
  HDU2015();
}
