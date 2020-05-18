//拉链法解决hash冲突
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

//开放寻址法解决hash冲突
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5+3, INF = 0x3f3f3f3f;  //INF表示一个hash中不存在的标志位
int h[N];

int find(int x){
    //找到元素x的所在的位置
    int k = (x % N + N) % N;
    while(h[k] != INF && h[k] != x){
        k++;
        if(k == N) k = 0;
    }
    return k;
}

int main(){
    int m;
    scanf("%d", &m);
    memset(h, 0x3f, sizeof(h));
    while(m--){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(!strcmp(op, "I")){
            int k = find(x);
            h[k] = x;
        }else{
            int k = find(x);
            if(h[k] != INF) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}