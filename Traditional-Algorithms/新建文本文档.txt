#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 310, INF = 0x3f3f3f3f;
int a[N], s[N];
int f[N][N];  //表示从i到j这段区间内的石子合并成一堆石子的合并方法，属性为求这些方式中代价的最小值
int n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];   //前缀和
    }
    
    //枚举区间长度
    for(int len = 2; len <= n; len++){   //区间长度一定是从2开始，因为如果区间长度为1，合并这一堆就不需要代价，也就是代价为0
        //枚举起始点
        for(int i = 1; i + len - 1 <= n; i++){   //枚举起点
            int l = i, r = i + len - 1; //知道了区间长度和起点，就能知道该区间的左右端点
            f[l][r] = INF;
            for(int k = l; k < r; k++){
                f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    
    printf("%d\n", f[1][n]);
    return 0;
}