//本题是最长下降子序列
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int a[N], f[N];
int k, n;

int main(){
    scanf("%d", &k);
    while(k--){
        scanf("%d", &n);
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++){
            f[i] = 1;
            for(int j = 0; j < n; j++){
                if(a[i] < a[j]) f[i] = max(f[i], f[j]+1);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, f[i]);
        }
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++){
            f[i] = 1;
            for(int j = 0; j < n; j++){
                if(a[i] > a[j]) f[i] = max(f[i], f[j]+1);
            }
        }
        for(int i = 0; i < n; i++){
            res = max(res, f[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}