#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];  //cnt表示从1到N存在的边的个数
bool visited[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa(){
    queue<int>q;
    for(int i = 1; i <=n; i++){
        visited[i] = true;
        q.push(i);
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();
        visited[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t]+ 1;
                if(cnt[j] >= n) return true;  //如果从1到j的边数大于等于n，那么说明在1到j上一定存在n+1个点，但是题目只有n个点，推出矛盾。由抽屉原理可知两个点重复，并且这两个点之间的路径在减小，因为我们选择路径减小的方向做更新
                if(!visited[j])
                    q.push(j);
					visited[j] = true;
            }
        }
    }
    return false;
}


int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if(spfa()) printf("Yes\n");
    else printf("No\n");
    return 0;
}