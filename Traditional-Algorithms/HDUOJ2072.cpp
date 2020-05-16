#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

const int maxn = 1e4 + 5;
int tree[maxn][30];
bool vis[maxn];
int cnt;

inline void insert(char s[]){
    int u = 0;
    for (int i = 0;s[i];++i){
        int id = s[i] - 'a';
        if (!tree[u][id]){
            tree[u][id] = ++cnt;
        }
        u = tree[u][id];
    }
    vis[u] = 1;
}

inline void search(){
    int ans = 0;
    for (int i = 0;i <= cnt;++i){
        if (vis[i]){
            ++ans;
        }
    }
    printf("%d\n",ans);
}

int main(){
    string tmp;
    while (getline(cin,tmp) && tmp != "#"){
        stringstream ss(tmp);
        char s[50];
        while (ss >> s){
            insert(s);
        }
        search();
        cnt = 0;
        memset(tree,0,sizeof(tree));
        memset(vis,0,sizeof(vis));
    }
    return 0;
}