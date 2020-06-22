// 参考链接 https://oi-wiki.org/math/quick-pow/
#include <iostream>
using namespace std;
typedef long long LL;

// 计算 a^k % p
int qmi(int a, int p, int k){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, p;
        scanf("%d%d", &a, &p);
        int res = qmi(a, p, p-2);   // 实际上是求a^(k-2) 快速幂公式
        if(a % p) printf("%d\n", res);
        else puts("impossible");
    }
    return 0;
}