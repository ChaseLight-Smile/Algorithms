// 最大子序和，单调队列+前缀和
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

typedef long long LL;
const int N = 300010;
int q[N];
LL s[N];
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &s[i]);  //这里要注意读入long long时用lld
        s[i] += s[i-1];
    }
    
    int hh = 0, tt = -1;
    q[++tt] = 0;  //表示设置s[0] = 0
    LL res = INT_MIN;
    for(int i = 1; i <= n; i++){
        res = max(res, s[i] - s[q[hh]]);  //先计算最值
        if(q[hh] < i - m + 1) hh++；  //后判断是否需要弹出
        while(hh <= tt && s[q[tt]] >= s[i]) tt--; //判断当前i是否要进队列，找到合适的位置
        q[++tt] = i; //当前i进队列
    }
    printf("%d\n", res);
    return 0;
}