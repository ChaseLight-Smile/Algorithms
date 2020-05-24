#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];
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
                cnt[j] = cnt[n]+ 1;
                if(cnt[j] > n) return true;
                if(!visited[j])
                    q.push(j);
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