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

const int N = 510, M = 5010;
const int INF = 0x3f3f3f3f;
int v[N];
int w[N];
int f[M];   //表示价值为j(这里不是<=j，所以一定要注意初始化f[0] = 0, f[i] = INF, 使用INF的原因是求的是最小值)的最小重量，从题意中知道价值的最大值为5000
int n, m;

int main(){
    int loop;
    scanf("%d", &loop);
    while(loop--){
        memset(v, 0, sizeof v);
        memset(w, 0, sizeof w);
        memset(f, INF, sizeof f);
        f[0] = 0;
        scanf("%d%d", &n, &m);
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &w[i], &v[i]);
            sum += v[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = sum; j >= v[i]; j--){ //枚举价值
                f[j] = min(f[j], f[j-v[i]]+w[i]);
            }
        }
        for(int i = sum; i >= 0; i--){
            if(f[i] <= m){   //m表示背包的最大重量，找到第一个重量小于等于最大重量的价值终止枚举过程
                printf("%d\n", i);
                break;
            }
        }
    }
    
    return 0;
}