/*  1s在C++中能计算1e9，分析本题三重循环，得到1e6，不会TLE
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤100
0<vi,wi,si≤100
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/


#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i =1; i <= n; i++){
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
    }
    
    for(int i = 1; i <= n; i++){  //i枚举物品
        for(int j = 0; j <= m; j++){  //枚举物品体积
            for(int k =0; k * v[i] <= j && k <= s[i] ; k++){  //枚举选择几个第i个物品
                f[i][j] = max(f[i][j], f[i-1][j-v[i]*k] + w[i] * k);
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}

//一维
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int n, m;
int v[N], w[N], s[N];
int f[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i =1; i <= n; i++){
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
    }
    
    for(int i = 1; i <= n; i++){  //i枚举物品
        for(int j = m; j >= v[i]; j--){  //枚举物品体积
            for(int k =0; k * v[i] <= j && k <= s[i] ; k++){  //枚举选择几个第i个物品
                f[j] = max(f[j], f[j-v[i]*k] + w[i] * k);
            }
        }
    }
    printf("%d\n", f[m]);
    return 0;
}