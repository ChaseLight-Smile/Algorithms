/**
给定n个0和n个1，它们将按照某种顺序排成长度为2n的序列，求它们能排列成的所有序列中，能够满足任意前缀序列中0的个数都不少于1的个数的序列有多少个。
输出的答案对109+7取模。
输出格式
共一行，包含整数n。
输出格式
共一行，包含一个整数，表示答案。
数据范围
1≤n≤105 
输入样例：
3
输出样例：
5
*/

//重点是catalan的转换过程
#include <iostream>
using namespace std;
const int mod = 1e9+7;
typedef long long LL;

int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res* a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int a = 2 * n, b = n;
    int res = 1;
    
    for(int i = a; i > a-b; i--) res = (LL)res * i % mod;
    for(int i = 1; i <= b; i++) res = (LL)res * qmi(i, mod-2, mod) % mod;
    res = (LL)res * qmi(n+1, mod-2, mod) % mod;
    cout << res << endl;
    return 0;
}