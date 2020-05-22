#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int g[N][N];
int dist[N];
bool visited[N];
int n, m;

int dijkstra(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0 ; i < n ; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!visited[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        visited[t] = true;
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    
    int k = dijkstra();
    printf("%d", k);
    return 0;
}


//堆优化dijkstra算法，时间复杂度为O(mlogn)，使用链式前向星存储
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 150010;
typedef pair<int, int>PII;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool visited[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>>q;
    q.push({0, 1}); //0表示1到1的距离，1表示起始点
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int dis = t.first, point = t.second;
        if(visited[point]) continue;
        visited[point] = true;
        for(int i = h[point]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dis + w[i]){
                dist[j] = dis + w[i];
                q.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int k = dijkstra();
    printf("%d", k);  
    return 0;
}