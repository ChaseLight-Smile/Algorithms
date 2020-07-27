/**
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
8
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, m;  // n表示物品的数量，m表示背包的容积
int v[N], w[N]; // V表示每件物品的体积，W表示每件物品的价值
int f[N][N];  //状态表示

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0){
                f[0][j] = 0;   //初始化边界要注意，因为我们将状态数组定义在全局，所以其自动初始化为0，所以删除这个if条件结果仍然正确
                continue;
            }
            f[i][j] = f[i-1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i]);
        }
    }
    
    cout << f[n][m] << endl;
    return 0;
}


//使用滚动数组优化，从上面的代码中，直接将f[i][j]中的i维去掉
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N], f[N];  //f只剩一维

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = m; j >= v[i]; j--){  //去掉i维，只能从最大值到最小值
            if(i == 0){
                f[j] = 0;
                continue;
            }
            f[j] = max(f[j], f[j-v[i]]+w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}

//不保存v、w的方法，一边读一边处理，过程更加简洁
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int f[N];
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        int v, w;
        scanf("%d%d", &v, &w);
        for(int j = m; j >= v; j--){
            f[j] = max(f[j], f[j-v]+w);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}