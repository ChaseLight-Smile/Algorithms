#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 1e5+10;
int h[N], e[M], ne[M], idx;
int match[N];
bool visited[N];
int n1, n2, m;

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!visited[j]){
            visited[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d%d", &n1, &n2, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a,b);
    }
    
    int res = 0;
    for(int i = 1; i <= n1; i++){
        memset(visited, false, sizeof visited);
        if(find(i)) res++;
    }
    printf("%d\n", res);
    return 0;
}