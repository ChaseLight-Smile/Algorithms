#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool visited[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int>q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        visited[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!visited[j])
                    q.push(j);
					visited[j] = true;
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int v = spfa();
    if(v == -1){
        printf("impossible\n");
    }else printf("%d\n", v);
    return 0;
}