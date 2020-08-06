/** 区间选点
给定N个闭区间[ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
输出选择的点的最小数量。
位于区间端点上的点也算作区间内。
输入格式
第一行包含整数N，表示区间数。
接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。
输出格式
输出一个整数，表示所需的点的最小数量。
数据范围
1≤N≤105,
−109≤ai≤bi≤109
输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/


/**  最大不相交区间个数 和上一个题目的解法完全一致
给定N个闭区间[ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。
输出可选取区间的最大数量。
输入格式
第一行包含整数N，表示区间数。
接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。
输出格式
输出一个整数，表示可选取区间的最大数量。
数据范围
1≤N≤105,
−109≤ai≤bi≤109
输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/

// 贪心解，按照右端点从小到大排序
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n;
struct Range{
    int l, r;
    
}range[N];
struct cmp{
    bool operator()(const Range &W1, const Range &W2)const{
        return W1.r < W2.r;
    }
};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }
    sort(range, range+n, cmp());
    int res = 0, INF = -2e9+7;
    for(int i = 0; i < n; i++){
        if(INF < range[i].l){
            res++;
            INF = range[i].r;
        }
    }
    printf("%d\n", res);
    return 0;
}

//贪心解，给出两种重载运算符的方法，按照右端点从小到大排序
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n;
struct Range{
    int l, r;
    bool operator<(const Range &W)const{
        return r < W.r;
    }
}range[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }
    sort(range, range+n);
    int res = 0, INF = -2e9+7;
    for(int i = 0; i < n; i++){
        if(INF < range[i].l){
            res++;
            INF = range[i].r;
        }
    }
    printf("%d\n", res);
    return 0;
}

//贪心解，按照左端点从小到大排序
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n;
struct Range{
    int l, r;
}range[N];

struct cmp{
    bool operator()(const Range & W1, const Range & W2){
        return W1.l < W2.l;   //按照左端点从小到大排序
    }
};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }
    sort(range, range+ n, cmp());
    int res = 0, INF = -2e9+7;  //INF表示右端点
    for(int i = 0; i < n; i++){
        if(range[i].l > INF){
            res++;
            INF = range[i].r;
        }else{
            INF = min(INF, range[i].r);
        }
    }
    printf("%d\n", res);
    return 0;
}
