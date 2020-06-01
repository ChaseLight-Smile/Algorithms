// O(sqrt(n))的时间复杂度
#include <iostream>
using namespace std;

int n, m;
void factor(int n){
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){  //一定是一个质因数
            int count  = 0 ;
            while(n % i == 0){  //求该质因数的个数
                n /= i;
                count++;
            }
            printf("%d %d\n", i, count);
        }
    }
    if(n > 1) printf("%d %d\n", n , 1);  // 唯一一个大于sqrt(n)的质因数
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        factor(m);
        printf("\n");
    }
    return 0;
}