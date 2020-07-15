/**
给定n组询问，每组询问给定三个整数a,b,p，其中p是质数，请你输出Cba mod p的值。
输入格式
第一行包含整数n。
接下来n行，每行包含一组a,b,p。
输出格式
共n行，每行输出一个询问的解。
数据范围
1≤n≤20,
1≤b≤a≤1018,
1≤p≤105 ,
输入样例：
3
5 3 7
3 1 5
6 4 13
输出样例：
3
3
2
*/

// 使用lucas定理，时间复杂度为logN* p * logp https://oi-wiki.org/math/lucas/
// 使用lucas定理，c(a,b) 同余 c(a%p, b%p) + c(a/p, b/p) % p 两个结果在mod p的情况下是同余关系
// https://blog.csdn.net/qq_40679299/article/details/80489761

#include <iostream>
using namespace std;

typedef long long LL;
int p;  //题目中的p

int qmi(int a, int k){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res* a %p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int c(int a, int b){
    int res = 1;
    for(int i = 1, j = a; i <= b; i++, j--){
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p-2) % p;
    }
    return res;
}

int lucas(LL a, LL b){
    if(a < p && b < p) return c(a,b);
    return (LL)c(a%p, b%p) * lucas(a/p, b/p) % p;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        LL a, b;
        scanf("%ld%ld%ld", &a, &b, &p);
        printf("%d\n", lucas(a, b));
    }
    return 0;
}
