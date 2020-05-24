#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210;
int d[N][N];
int n, m, q;

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main(){
    scanf("%d%d%d", &n, &m, &q);
    //初始化d[N][N]数组
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;  //如果出现自环，直接去掉
            else d[i][j] = 0x3f3f3f3f;
        }
    }
    
    while(m--){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        d[a][b] = min(d[a][b], w); //如果出现重边，只保留权值小的
    }
    
    floyd();
    while(q--){
        int i, j;
        scanf("%d%d", &i, &j);
        if(d[i][j] > 0x3f3f3f3f /2) printf("impossible\n");
        else printf("%d\n", d[i][j]);
    }
    return 0;
    
}

//floyd的设计基于动态规划，其状态转移方程为：dp[k, i, j] = dp[k-1,i, k] + dp[k-1, k, j];  其中k表示阶段，能够从状态转移方程中删除dp[i, j] = dp[i, k] + dp[k, j];