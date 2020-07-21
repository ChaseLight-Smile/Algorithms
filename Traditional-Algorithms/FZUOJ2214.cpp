//爆内存，
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510, M = 1e7+10;  //题意这里为1e9+10
int v[N], w[N];
int f[M];
int n, m;
int main(){
    int loop;
    scanf("%d", &loop);
    while(loop--){
        memset(v, 0, sizeof v);
        memset(w, 0, sizeof w);
        memset(f, 0, sizeof f);
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d%d", &w[i], &v[i]);
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= w[i]; j--){ //最大是1e9
                f[j] = max(f[j], f[j-w[i]]+v[i]);
            }
        }
        printf("%d\n", f[m]);
    }
    
    return 0;
}


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 510, M = 1e4+10;
const ll INF = 0x3f3f3f3f;
int v[N];
ll w[N];
ll f[M];

ll n, m;
int main(){
    int loop;
    scanf("%d", &loop);
    while(loop--){
        memset(v, 0, sizeof v);
        memset(w, 0, sizeof w);
        memset(f, INF, sizeof f);
        f[0] = 0;
        scanf("%lld%lld", &n, &m);
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%lld%lld", &w[i], &v[i]);
            sum += v[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = sum; j >= v[i]; j--){
                f[j] = min(f[j], f[j-v[i]]+w[i]);
            }
        }
        for(ll i = sum; i >= 0; i--){
            if(f[i] <= m){
                printf("%lld\n", i);
                break;
            }
        }
    }
    
    return 0;
}