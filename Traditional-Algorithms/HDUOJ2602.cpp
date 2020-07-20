#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N];
int loop, n, m;
int main(){
    scanf("%d", &loop);
    while(loop--){
        memset(v, 0, sizeof v);
        memset(w, 0, sizeof w);
        memset(f, 0, sizeof f);
        
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%d", &w[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &v[i]);
        }
        for(int i = 1; i <= n;i++){
            for(int j = m; j >= v[i]; j--){
                f[j] = max(f[j], f[j-v[i]]+w[i]);
            }
        }
        printf("%d\n", f[m]);
    }
    return 0;
}