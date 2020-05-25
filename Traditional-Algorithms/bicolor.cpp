#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5+10, M = 2e5+10;
int h[N], e[M], ne[M], idx;
int n, m;
int color[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u, int c){
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j, 3-c)) return false;
        }else if (color[j] == c) return false;
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d", &a, &b);
        add(a,b), add(b,a);
    }
    
    bool flag = true;
    for(int i = 1 ; i <= n; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}