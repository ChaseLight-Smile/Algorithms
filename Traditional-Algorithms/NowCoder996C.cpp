//整个思路和快速幂很像，但是用加法代替了乘法
#include <iostream>
using namespace std;
typedef long long LL;
int main(){
    LL a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    LL res = 0;
    while(b){
        if(b & 1) res = (res+a)%p;
        a = a * 2 % p;
        b >>= 1;
    }
    printf("%lld\n", res);
    return 0;
}