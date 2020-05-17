//dijkstra最短路径算法中用到的堆优化，这个堆维护的信息比普通的堆更多，STL的堆很难实现这个部分
#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e5+10;
int h[N], ph[N], hp[N], len;   //ph根据插入元素的顺序映射到堆中的位置， hp是根据堆中的位置，找到其插入堆时的顺序

//a， b均指在堆中的位置
void heap_swap(int a, int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);   //先交换上述两个指针的指针
    swap(h[a], h[b]);   //在交换具体堆中的数据
}

void down(int u){
    int t = u;
    if(u * 2 <= len && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= len && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if(u != t){
        heap_swap(u,t);
        down(t);
    }
}

void up(int u){
    if(u / 2 >= 1 && h[u / 2] > h[u]){
        heap_swap(u/2, u);
        up(u/2);  //这个能改成迭代
    }
}

int main(){
    int m, p = 0;
    scanf("%d", &m);
    while(m--){
        char op[5];
        scanf("%s", op);
        int k, x;
        if(!strcmp(op, "I")){   //插入操作在堆尾执行，然后再up到正确的位置
            scanf("%d", &x);
            len++;
            p++; //表示第p个被插入的数
            ph[p]= len;
            hp[len] = p;
            h[len] = x;   //位置和上面两个交换的顺序不能反
            up(len);
        }else if (!strcmp(op, "PM")){ //PM指的是输出当前集合的最小值
            printf("%d\n", h[1]);
        }else if(!strcmp(op, "DM")){  //DM指的是删除堆顶元素
            //表示删除堆顶元素
            heap_swap(1, len);
            len--;
            down(1);
        }else if (!strcmp(op, "D")){  //删除第k个插入的数
            scanf("%d", &k);
            k = ph[k]; //根据ph[k]找到在堆中的位置
            heap_swap(k, len);
            len--;
            down(k), up(k);  //这两个操作只会执行一个
        }else{  //这里指修改第k个插入的数
            scanf("%d%d", &k, &x);
            k = ph[k];  //找到第k个插入的数在堆中的位置
            h[k] = x;
            down(k), up(k);  //这俩操作只会有一个操作能够被执行
        }
    }
    return 0;
}