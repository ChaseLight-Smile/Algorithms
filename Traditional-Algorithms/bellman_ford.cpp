// 大力出奇迹算法
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 10010;
int n, m, k;
int dist[N], backup[N];

struct Edge{
    int a, b, w;
}edge[M];

int bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k; i++){
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; j++){
            int a = edge[j].a, b = edge[j].b, w = edge[j].w; 
            dist[b] = min(dist[b], backup[a] + w);   //三角形不等式松弛
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
    
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0 ; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    
    int v = bellman_ford();
    if(v == -1) printf("impossible\n");
    else printf("%d\n", v);
    return 0;
}