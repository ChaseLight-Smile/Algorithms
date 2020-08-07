/**
给定N个闭区间[ai,bi]以及一个线段区间[s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。
输出最少区间数，如果无法完全覆盖则输出-1。
输入格式
第一行包含两个整数s和t，表示给定线段区间的两个端点。
第二行包含整数N，表示给定区间数。
接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。
输出格式
输出一个整数，表示所需最少区间数。
如果无解，则输出-1。

数据范围
1≤N≤105,
−109≤ai≤bi≤109,
−109≤s≤t≤109
输入样例：
1 5
3
-1 3
2 4
3 5
输出样例：
2
*/

/**
(1)首先按照左端点排序
(2)在所有能覆盖start的区间中，选择右端点最大的一个作为新的start，直到所有的区间都被扫描完
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5+10;
int s, t, n;
PII range[N];

int main(){
    scanf("%d%d%d", &s, &t, &n);
    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l,r};
    }
    sort(range, range + n);   //利用了pair本身的特性，按照左端点排序，如果做左端点相同则只按照右端点排序
    priority_queue<int>q;   //大顶堆
    int res = 0;
    bool success = false;
    for(int i = 0; i < n; i++){
        int j = i, r = -2e9;
        while(j < n && range[j].first <= s){
            r = max(r, range[j].second);
            j++;   //遍历所有左端点小于s的区间，并且找到右端点的最大值
        }
        if(r < s){
            break;
        }
        res++;
        if(r >= t){
            success = true;
            break;
        }
        s = r;
        i = j-1;
    }
    if(!success)res = -1;
    printf("%d\n", res);
    return 0;
}