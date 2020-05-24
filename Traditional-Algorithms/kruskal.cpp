#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5+10;
int p[N];
int n, m;
struct Edge{
    int a, b, w;
    bool operator< (const Edge & W)const{
        return w < W.w;
    }
}edge[N];

int find(int x){
    if(p[x] != x) return p[x] = find(p[x]);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    
    sort(edge, edge+m);
    for(int i = 1; i <= n; i++) p[i] = i;
    int res = 0,  cnt = 0;
    for(int i = 0; i < m; i++){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if(a != b){
            p[a] = b; // 将a的父亲节点设置为b，表示a与b在同一个集合中
            res += w;
            cnt++;
        }
    }
    if(cnt < n-1) printf("impossible\n");
    else printf("%d\n", res);
    return 0;
}