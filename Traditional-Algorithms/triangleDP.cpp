// http://bailian.openjudge.cn/practice/2760/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int a[N][N], f[N][N];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i+1; j++){
            f[i][j] = -INF; //这里初始化 把所有的边界都包含了
        }
    }
    f[1][1] = a[1][1];  //初始化
    // 计算状态
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            f[i][j] = max(f[i-1][j-1]+a[i][j], f[i-1][j]+a[i][j]);
        }
    }
    
    int ans = -INF;
    for(int i = 1; i <= n; i++){
        ans = max(ans, f[n][i]);
    }
    printf("%d\n", ans);
    
    return 0;
}