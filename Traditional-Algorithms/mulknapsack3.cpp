/**
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V (0<N≤1000, 0<V≤20000)，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N≤1000
0<V≤20000
0<vi,wi,si≤20000

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/


//本题算法时间复杂度为(N*V)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20010;
int f[N], g[N], q[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);
        
        for(int j = 0; j < v; j++){
            int hh = 0, tt = -1;
            for(int k = j; k <= m; k += v){
                f[k] = g[k];
                if(hh <= tt && k - s * v > q[hh]) hh++;
                if(hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
                while(hh <= tt && g[q[tt]] - (q[tt] - j)/ v * w <= g[k] - (k-j) / v * w) tt--;
                q[++tt] = k;
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}