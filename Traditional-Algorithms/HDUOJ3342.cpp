#include <iostream>
#include <cstring>
#include<functional>
#include <map>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], idx;
int q[N], d[N];  //入度集合
int n, m;

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort(){
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i++){
        if(!d[i]){
            q[++tt] = i;
        }
    }
    while(hh <= tt){
        int u = q[hh++];
        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(!d[j]){
                q[++tt] = j;
            }
        }
    }
    
    if(tt == n-1) return true;
    return false;
}

int main(){
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);
        while(m--){
            int a, b;
            cin >> a >> b;
            add(a, b);
            d[b]++;
        }
        if(topsort()){
            printf("YES\n");
        }else printf("NO\n");  
    }
    
    return 0;
}