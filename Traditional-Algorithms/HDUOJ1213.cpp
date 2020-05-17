#include <iostream>
using namespace std;

const int N = 1e5+10;
int p[N], s[N];

int find(int x){
    if(p[x]!=x) return p[x]=find(p[x]);
}

int main(){
    int n, m, k;
    scanf("%d", &k);
    while(k--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <=n; i++){
            p[i] = i;
            s[i] = 1; 
        }
    
        while(m--){
            int a, b;
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) continue;
            s[find(a)]--;
            p[find(a)] = find(b);
        }
        int ans = 0;
        for(int i = 1; i <=n; i++){
            if(s[i] != 0) ans += s[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}

