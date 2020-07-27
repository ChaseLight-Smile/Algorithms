#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3402+10, M = 12880+10;
int n, m;
int w[N], d[N];
int f[M];
int sumW[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &w[i], &d[i]);
		sumW[i] = sumW[i-1]+w[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= max(m - (sumW[n]-sumW[i+1]), w[i]); j--){
            f[j] = max(f[j], f[j-w[i]]+d[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}


//一个常数优化
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3402+10, M = 12880+10;
int n, m;
int w[N], d[N];
int f[M];
int sumW[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &w[i], &d[i]);
		sumW[i] = sumW[i-1]+w[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= max(m - (sumW[n]-sumW[i]), w[i]); j--){
            f[j] = max(f[j], f[j-w[i]]+d[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}