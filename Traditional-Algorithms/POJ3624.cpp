#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3402+10, M = 12880+10;
int n, m;
int w[N], d[N];
int f[M];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &w[i], &d[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j--){
            f[j] = max(f[j], f[j-w[i]]+d[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}