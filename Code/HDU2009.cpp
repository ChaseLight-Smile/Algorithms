#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double n, m;
    while (cin >> n){
        cin >> m;
        double sum = n;
        for (int i = 0; i < m-1 ; i++){
            double next = sqrt(n);
            sum += next;
            n = next;
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
