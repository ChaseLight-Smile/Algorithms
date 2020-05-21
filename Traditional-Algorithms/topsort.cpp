#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], idx; // 链式前向星
int q[N], d[N]; //q为队列，d表示图中节点的入度集合
int n,m;

void add(int a , int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <=n; i++){
        if(!d[i]){
            q[++tt] = i;   //如果这里需要将输出的结果序列按照某种次序排序，可以该用priority_queue来存储
        }
    }
    while(hh <= tt){
        int u = q[hh++];
        for(int i = h[u]; i != -1; i = ne[i]){
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
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);  //初始化链式前向星
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }
    if(topsort()){
        for(int i = 0; i < n; i++){
            printf("%d ", q[i]);
        }
    }else printf("-1\n");
}