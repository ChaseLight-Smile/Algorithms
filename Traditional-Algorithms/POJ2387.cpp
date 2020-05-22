#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e3+10, M = 2e3+10;
int g[N][N];
int n, m;
int dist[N];
bool visited[N];

int dijkstra(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0 ; i < m; i++){
        int t = -1;
        for(int j = 1; j <= m; j++){
            if(!visited[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        visited[t] = true;
        for(int j = 1; j <= m; j++){
            dist[j] = min(dist[j], dist[t]+g[t][j]);
        }
    }
    if(dist[m] == 0x3f3f3f3f) return -1;
    return dist[m];
}

int main(){
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while(n--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    
    int k = dijkstra();
    printf("%d\n", k);
    return 0;
}