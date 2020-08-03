/**
给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。
输入格式
第一行包含整数N。
第二行包含N个整数，表示完整序列。
输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤1000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/
// http://poj.org/problem?id=2533

//时间复杂度为O(n^2)，本题的时间复杂度为1e6。C++在1s内能够计算<1e9的数据规模，所以本题能够AC
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int f[N], a[N], g[N];   //所有以第i个数结尾的数值上升子序列的长度
int n;

int main(){
    scanf("%d", &n);
    for(int i =1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        f[i] = 1;   //只有a[i]一个数的请款下长度为1
        g[i] = 0;
        for(int j = 1; j <= i; j++){
            if(a[j] < a[i]){
                if(f[i] < f[j] + 1){
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
            }
        }
    }
    
    int k = 1;  //最终在k中保留了最长上升子序列的值
    for(int i = 1; i <= n; i++){
        if(f[k] < f[i]) k = i;
    }
    
    printf("%d\n", f[k]);
    while(k > 0){
        printf("%d ", a[k]);
        k = g[k];
    }   //求出最长上升子序列
    
    return 0;
}