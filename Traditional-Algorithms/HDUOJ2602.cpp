#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N];

int main(){
    int loop;
    scanf("%d", &loop);
    while(loop--){
        int n, m;
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