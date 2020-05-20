#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], idx;
int q[N], d[N]; //q表示队列,d表示节点的入度
int n , m;

void add(int a , int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <=n; i++){
        if(!d[i]){
            q[++tt] = i;
        }
    }
    
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(d[j] == 0){
                q[++tt] = j;
            }
        }
    }
    if(tt == n-1){
        return true;
    }else return false;
    
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a,b);
        d[b]++;
    }
    if(topsort()){
        for(int i = 0; i < n; i++){
            cout << q[i] << " "; 
        }
    }else puts("-1\n");
    return 0;
}