/**
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7 的结果。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一个整数，表示 方案数 模 109+7 的结果。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 6
输出样例：
2
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010, mod = 1e9+7;
int f[N], g[N];   //f表示恰好为j时的最大价值，g表示取到j时的的方案数，跟最值型时的转移方程含义不同
int n, m;

int main(){
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;  //根据f[0] = 0,可以知道体积恰好为0时，最大价值为0，此时的方案数只有一种，因此g[0] = 1
    for(int i = 1; i <= n; i++){
        int v, w;
        cin >> v >> w;
        for(int j = m; j >= v; j--){
            int cnt = 0;
            int maxv = max(f[j], f[j-v] + w);
            if(maxv == f[j]) cnt = (cnt + g[j]) % mod;
            if(maxv == f[j-v]+w) cnt = (cnt + g[j-v]) % mod;
            f[j] = maxv;
            g[j] = cnt % mod;
        }
    }
    int maxv = 0;
    int res = 0;
    for(int i = 0; i <= m; i++) maxv = max(maxv, f[i]); //遍历找到最大价值
    for(int i = 0; i <= m; i++){
        if(f[i] == maxv) res = (res + g[i]) % mod;  //搜索出价值最大的方案数并实现累加
    }
    cout << res << endl;
    return 0;
}