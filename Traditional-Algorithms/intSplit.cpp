// NOI 7215 http://noi.openjudge.cn/ch0207/7215/


//完全背包解法
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010, mod = 1e9+7;
int f[N];
int n;

int main(){
    scanf("%d", &n);
    f[0] = 1;   //初始化，当体积为0时，有一种方案能够满足条件，其余的f[i]的值为0，没有满足题意的方案
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            f[j] = (f[j] + f[j-i])  % mod;
        }
    }
    printf("%d\n",f[n]);
    return 0;
}


//计算型DP解法
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010, mod = 1e9+7;
int f[N][N]; //表示总和是i，并且恰好表示成j个数的和的方案总和
int n ;

int main(){
    scanf("%d", &n);
    f[0][0] = 1;
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % mod;   //要注意这里的划分方式
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = (res + f[n][i]) % mod;
    printf("%d\n", res);
    
    return 0;
}
