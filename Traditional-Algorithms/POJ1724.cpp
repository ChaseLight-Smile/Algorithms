#include <iostream>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;

const int N = 1e4+10;
int h[N], e[N], w[N], t[N], ne[N], idx;
int dist[N];
int sum[N];
bool visited[N];
typedef pair<int, pair<int, int>>PII;
int k, n , m;


void add(int a, int b, int c, int d){
    e[idx] = b;
    w[idx] = c;
    t[idx] = d;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    memset(sum, 0x3f, sizeof sum);
    dist[1] = 0;
    sum[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>>q;
    q.push({0,{0,1}}); //第一个位置表示代价，第二个0表示距离，表示点
    
    while(!q.empty()){
        auto tmp = q.top();
        q.pop();
        int s = tmp.first;
        auto point = tmp.second;
        if(visited[point.second]) continue;
        visited[point.second] =  true;
        for(int i = h[point.second]; i != -1; i = ne[i]){
            int j = e[i];
            if(sum[j] > s + t[i] || dist[j] > point.first + w[i]){
                dist[j] = point.first + w[i];
                sum[j] = s + t[i]; 
                q.push({sum[j], {dist[j], j}});
            }
        }
    }
    if(dist[n] != 0x3f3f3f3f && sum[n] <= k) return dist[n];
    return -1;
}

int main(){
    scanf("%d%d%d", &k, &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(a, b, c, d);
    }
    
    int k = dijkstra();
    printf("%d\n", k);
    return 0;
}