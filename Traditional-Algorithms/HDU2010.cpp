#include <iostream>
using namespace std;
void HDU2010(){
    int start;
    int end;
    while (cin >> start){
        cin >> end;
        int count = 0;
        if (start > end){
            int temp = start;
            start = end;
            end = temp;
        }
        for (int i = start; i <= end; i++){
            int sum;
            int m = i/100 ;
            int n = (i-m*100)/10;
            int p = (i%10);
            sum = m*m*m + n*n*n + p*p*p;
            if (sum == i){
                count++;
                if (count == 1){
                    cout << i;
                }else{
                    cout << " " << i ;
                }
            }
        }
        if (count == 0){
            cout << "no" << endl;
        }else{
            cout << endl;
        }
    }
}

int main(){
    HDU2010();
}
