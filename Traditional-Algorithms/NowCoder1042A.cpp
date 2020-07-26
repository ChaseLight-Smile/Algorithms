//01背包求方案数
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10010;
int n, m;
int f[N], g[N];

int main(){
    scanf("%d%d", &n, &m);
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;
    for(int i = 1; i <= n; i++){
        int v;
        scanf("%d", &v);
        for(int j = m; j >= v; j--){
            int cnt = 0;
            int maxv = f[j];
            if(j >= v) maxv = max(maxv, f[j-v]+v);
            if(maxv == f[j]) cnt += g[j];
            if(maxv == f[j-v] + v) cnt += g[j-v];
            f[j] =  maxv;
            g[j] = cnt;
        }
    }
    // cout << g[m] << endl;   //初始化决定了这个过程是正确的
     int res = 0;
     for(int i = 0; i <= m; i++){
         if(f[i] == m) res += g[i];
     }
     printf("%d\n", res);
    return 0;
}