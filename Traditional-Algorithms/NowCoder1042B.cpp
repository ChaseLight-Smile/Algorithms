//完全背包问题，从小到大枚举即可
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 4010, mod = 2147483648;
LL f[N], g[N];
int v[N], w[N];
int n;

int main(){
    scanf("%d", &n);
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;
    for(int i = 1; i <= n; i++){
        v[i] = w[i] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = v[i]; j <= n; j++){
            int cnt = 0;
            int maxv = max(f[j], f[j-v[i]]+w[i]);
            if(maxv == f[j]) cnt = (cnt+g[j])%mod;
            if(maxv == f[j-v[i]]+w[i]) cnt = (cnt+g[j-v[i]])%mod;
            f[j] = maxv;
            g[j] = cnt % mod;
        }
    }
    LL res = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] == n) res = (res+g[i])%mod;
    }
    printf("%d\n", res-1); 
}