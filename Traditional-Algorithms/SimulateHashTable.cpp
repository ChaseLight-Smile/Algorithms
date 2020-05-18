#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+3;
int h[N], e[N], ne[N], idx;
void insert(int x){
    int k = (x % N + N) % N;
    //将x插入到k位置
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

bool find(int x){
    int k = (x % N + N)%N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x){
            return true;
        }
    }
    return false;
}

int main(){
    memset(h, -1, sizeof(h));
    int m;
    scanf("%d", &m);
    while(m--){
        char op[2];
        int x;
        scanf("%s", op);
        scanf("%d", &x);
        if(!strcmp(op, "I")){
            insert(x);
        }else{
            if(find(x)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}