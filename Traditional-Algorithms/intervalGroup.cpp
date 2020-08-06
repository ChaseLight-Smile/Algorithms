/**
给定N个闭区间[ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。
输出最小组数。
输入格式
第一行包含整数N，表示区间数。
接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。
输出格式
输出一个整数，表示最小组数。
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
//贪心解，首先将区间按照左端点从小到大排序，然后依次处理每个区间，最关键的问题是，确定当前区间是否和已有的区间有交集
//判断方法是用一个小顶堆维护一个每个分组区间的最大值，如果当前区间的左端点值小于小顶堆的堆顶，那么说明这个区间一定和
//已有分组有交集，因此重新申请一个新的组（也就是往小顶堆中插入该区间的右端点），否则的话，说明和堆顶的区间无交集，则将该值插入到
//堆顶的分组中，也就是替换当前右端点的值，由于只看究竟有多少分组，所以根本不需要保存每个分组具体的每一个区间，只需要记录其最大的右端点值即可
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n;
struct Range{
    int l, r;
    bool operator<(const Range & W)const{
        return l < W.l;   //按照左端点从小到大排序
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
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++){
        if(q.empty() || q.top() >= range[i].l){
            //说明这个区间跟任何一个区间都有交集，所以只能新开一个新的组
            q.push(range[i].r);
        }else{
            int t = q.top();
            q.pop();
            q.push(max(t, range[i].r));
        }
    }
    printf("%d\n", q.size());
    return 0;
}
