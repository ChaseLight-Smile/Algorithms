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

//对应dd大神的1.5节“一个常数优化”，为什么会有这样的优化方式呢？
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int f[N];
int n, m;
int v[N], w[N];
int sumV[N];   //前缀和数组

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &v[i], &w[i]);
        sumV[i] = sumV[i-1] + v[i];
    }    
    for(int i = 1; i <= n; i++){
        for(int j = m; j >=  max(m - (sumV[n] - sumV[i]), v[i]); j--){
            f[j] = max(f[j], f[j-v[i]]+w[i]);
        }
       
    }
    printf("%d\n", f[m]);
    return 0;
}

/**
描写叙述
ltl 很喜欢玩warcraft。由于warcraft十分讲究团队总体实力，而他自己如今也为升级而不拖累团队而努力。
他如今有非常多个地点来选择去刷怪升级，可是在每个地点他都要买上充足的补给和合适的道具。以免在刷怪的时候被怪物反杀了。每个地点的怪物打完了就没有了（还竟然不掉金钱跟装备），并且他仅仅要选定了地点就一定会刷完该地点所有的怪物，同一时候获得相应的经验值。如今ltl 能给出每个地点用来买补给和道具的钱和打完所有怪物所能获得的经验。可是他所拥有的钱是一定的。
所以他想知道怎么选择地点使得他获得的经验最高。
输入
第一行一个整数T，表示測试数据的组数 0<T<=10
第二行两个整数N,M，0<N<=100,0<M<=1000000表示ltl拥有N个不同地点的选择和M的金钱总数
接下来N行每行两个整数ci,vi，(0<ci<=1000000,0<vi<=2000)表示ltl刷完第i个地点所须要购买补给和道具的总钱数和能获取的总经验值
输出
一行一个整数。表示ltl可以获取的最大的经验值
例子输入
2
3 10
7 7
2 3
3 5
2 5
3 5
2 1
例子输出
Max experience: 12
Max experience: 6
*/

//看似是一个很简单的题目，但是由于M过大，导致超时，需要用到上面提到的常数优化方可AC