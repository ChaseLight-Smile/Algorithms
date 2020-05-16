#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

const int N = 1e6+10;
int son[N][26], cnt[N], idx;

void insert(char str[]){
    int p = 0;
    for(int i = 0 ; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    if(cnt[p] == 0)
        cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) break;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    string tmp;
    while(getline(cin,tmp) && tmp != "#"){
        int count = 0;
        stringstream ss(tmp);
        char s[50];
        while (ss >> s){
            insert(s);
        }
        for(int i = 0 ; i <= idx; i++){
            count += cnt[i];
        }
        memset(cnt,0,sizeof(cnt));
        idx = 0;
        printf("%d\n", count);
    }
    
    return 0;
}