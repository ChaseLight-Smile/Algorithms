#include <iostream>
#include <cstring>
#include <queue>
#include<functional>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], idx;
priority_queue<int, vector<int>, greater<int>>q;
int d[N];
int n, m;

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void topsort(){
    for(int i = 1; i <= n; i++){
        if(!d[i]){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u = q.top();
        ans.push_back(u);
        q.pop();
        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(!d[j]){
                q.push(j);
            }
        }
    }
    for(int i = 0 ; i < ans.size()-1; i++){
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[ans.size()-1]);

    return;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){  //输入若干组数据
        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);
        for(int i = 0 ; i < m; i++){
            int a, b;
            scanf("%d%d",&a,&b);
            add(a,b);
            d[b]++;
        }
        topsort();
    }
    return 0;
}