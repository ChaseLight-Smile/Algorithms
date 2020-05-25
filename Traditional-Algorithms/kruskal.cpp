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
    
    sort(edge, edge+m);   //1. 对边排序
    for(int i = 1; i <= n; i++) p[i] = i; //初始化并查集

    int res = 0,  cnt = 0;
    for(int i = 0; i < m; i++){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if(a != b){  //3. 判断两个点是否在同一个连通块中，如果不在，将两个点合并到同一个连通块中，合并操作为p[a] = b 或者p[b] = a
            p[a] = b; // 将a的父亲节点设置为b，表示a与b在同一个集合中
            res += w;
            cnt++;
        }
    }
    if(cnt < n-1) printf("impossible\n");  //n个点的最小生成树应该包含n-1条边，如果小于n-1说明当前点不连通
    else printf("%d\n", res);
    return 0;
}


//代码中提供了两种实现operator<运算符重载的方式
#include <iostream>
#include <algorithm>
using namespace std;

const int M = 2e5+10;
int n, m;
int p[M];
int cnt;
struct Edge{
    int a, b, w;
    // bool operator< (const Edge &W)const{
    //     return w < W.w;
    // }
}edge[M];

struct cmp{
     bool operator() (const Edge &W1, const Edge &W2)const{
        return W1.w < W2.w;
    }
};

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
    int res = 0;
    //sort(edge, edge+m);   //operator< 定义在struct Edge内
    sort(edge, edge+m, cmp());
    for(int i = 1; i < n; i++){
        p[i] = i; //初始化并查集
    }
    
    for(int i = 0 ; i < m; i++){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if(cnt < n-1) printf("impossible\n");
    else printf("%d\n", res);
    return 0;
    
}

