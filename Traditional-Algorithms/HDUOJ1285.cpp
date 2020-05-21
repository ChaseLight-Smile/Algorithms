#include <iostream>
#include <cstring>
#include <queue>
#include<functional>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], idx;
priority_queue<int, vector<int>, greater<int>>q;  //小顶堆
int d[N];  //入度集合
int n, m;
vector<int> ans;

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
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1];

    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    topsort();
    return 0;
}