#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];   //表示当前点到最小生成树集合中的点的最小距离
bool visited[N];
int n, m;

int prim(){
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for(int i = 0 ; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!visited[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        if(i && dist[t] == INF) return INF;
        if(i) res += dist[t];   //应该先将距离家到最小生成树中，然后才能用该点去更新其它点的距离
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], g[t][j]);
        }
        visited[t] = true;   //将当前t设置为已经处理
    }
    
    return res;
}


int main(){
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);   //prim是无向图的最小生成树
    }
    int v = prim();
    if(v == INF) printf("impossible\n");
    else printf("%d\n", v);
    
    return 0;
    
}