// 快速幂能将时间复杂度从O(n)降低到O(logn)
#include <iostream>
using namespace std;

typedef long long LL;

// 计算a^k % p
int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res * a % p;   //快速幂过程
        k >>= 1;   //将最低位移出
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);
        printf("%d\n", qmi(a, k, p));
    }
    return 0;
}