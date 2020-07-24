/**
有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M。
每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V,M，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。
接下来有 N 行，每行三个整数 vi,mi,wi，用空格隔开，分别表示第 i 件物品的体积、重量和价值。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N≤1000
0<V,M≤100
0<vi,mi≤100
0<wi≤1000
输入样例
4 5 6
1 2 3
2 4 4
3 4 5
4 5 6
输出样例：
8
*/


//题目中说：每件物品只能用一次，说明这是01背包问题的扩展
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int n, v, m;
int f[N][N];

int main(){
    scanf("%d%d%d", &n, &v, &m);
    for(int i = 1; i <= n; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        for(int j = v; j >= a; j--){
            for(int k = m; k >= b; k--){
                f[j][k] = max(f[j][k], f[j-a][k-b] + c);
            }
        }
    }
    printf("%d\n", f[v][m]);
    return 0;
}