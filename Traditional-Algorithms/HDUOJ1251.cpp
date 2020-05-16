#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6+10;
int son[N][26], cnt[N], idx;

void insert(char str[]){
    int p = 0;
    int len = strlen(str);
    for(int i = 0 ; i < len; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        cnt[son[p][u]]++;
        p = son[p][u];
    }
    
    return;
}

int query(char str[]){
    int p = 0;
    int len = strlen(str);
    for(int i = 0 ; i < len; i ++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}


int main(){
    char s[20];
    //while(gets(s)){    //在新版本编译器中，gets函数被完全弃用，但是在HDUOJ的编译器中可以使用
    while(cin.getline(s,20)){
        if(strlen(s) == 0){
            break;
        }
        insert(s);
    }
    //while(gets(s)){
    while(cin.getline(s,20)){
        printf("%d\n", query(s));
    }
    return 0;
}