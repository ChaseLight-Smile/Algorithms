#include <iostream>
#include <cmath>
using namespace std;
void HDU2011(){
    int m;
    while (cin>>m){
        int n;
        for (int i = 0;i < m; i++){
            cin >> n;
            double sum = 0;
            for (int j = 1; j <= n; j++){
                sum += pow(-1,j-1)*(1/(double)(j));
            }
            printf("%.2f\n",sum);
        }
    }
}
int main(){
    HDU2011();
    return 0;
}
