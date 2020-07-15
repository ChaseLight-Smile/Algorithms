/**
给定n组询问，每组询问给定两个整数a，b，请你输出Cba mod (109+7)的值。
输入格式
第一行包含整数n。
接下来n行，每行包含一组a和b。
输出格式
共n行，每行输出一个询问的解。
数据范围
1≤n≤10000 ,
1≤b≤a≤105
输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1
*/

//利用公式c(a,b) = a! / (b! * (a-b)!)，但是由于(a/b)%d != (a%d)/(b%d)，所以只能用逆元
// (a/b)%p = (a%p * b的逆元%p)%p https://www.cnblogs.com/hopelee/p/9523910.html 费马小定理可知逆元的求法
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+10, mod = 1e9+7;

int fact[N], infact[N];   //某个数及其逆元的阶乘

//a^k % p
int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (LL)fact[i-1]* i % mod;
        infact[i] = (LL)infact[i-1] * qmi(i, mod -2, mod) % mod;  //这里qmi表示i的逆元为i^mod-2
    }
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a-b] % mod);
    }
    return 0;  
}