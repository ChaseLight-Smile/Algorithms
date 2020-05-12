//UVa 数组模拟双向链表
/**
实现一个双链表，双链表初始为空，支持5种操作：
(1) 在最左侧插入一个数；
(2) 在最右侧插入一个数；
(3) 将第k个插入的数删除；
(4) 在第k个插入的数左侧插入一个数；
(5) 在第k个插入的数右侧插入一个数
现在要对该链表进行M次操作，进行完所有操作后，从左到右输出整个链表。
注意:题目中第k个插入的数并不是指当前链表的第k个数。例如操作过程中一共插入了n个数，则按照插入的时间顺序，这n个数依次为：第1个插入的数，第2个插入的数，…第n个插入的数。
输入格式
第一行包含整数M，表示操作次数。
接下来M行，每行包含一个操作命令，操作命令可能为以下几种：
(1) “L x”，表示在链表的最左端插入数x。
(2) “R x”，表示在链表的最右端插入数x。
(3) “D k”，表示将第k个插入的数删除。
(4) “IL k x”，表示在第k个插入的数左侧插入一个数。
(5) “IR k x”，表示在第k个插入的数右侧插入一个数。
输出格式
共一行，将整个链表从左到右输出。
数据范围
1≤M≤100000
所有操作保证合法。
输入样例：
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
输出样例：
8 7 7 3 2 9
*/

#include <iostream>
using namespace std;

const int N = 1e5+10;

int e[N], l[N], r[N], idx;

void init(){
    r[0] = 1;   //0表示链表头
    l[1] = 0;   //1表示链表尾
    idx = 2;    //链表中的有效的数据从2开始
}

//在k位置之后，增加一个节点
void add(int k, int x){
    e[idx] = x; //设置该节点的value为x
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

//删除k位置之后的节点
void del(int k){
    r[k] = r[r[k]];
    l[r[k]] = k;
}

int main(){
    init();
    int n;
    cin >> n;
    while(n--){
        string op;
        int k, x;
        cin >> op;
        if(op == "L"){
            cin >> x;
            add(0, x);
        }else if(op == "R"){
            cin >> x;
            add(l[1], x);
        }else if(op == "D"){
            cin >> k;
            del(l[k+1]);
        }else if(op == "IL"){
            cin >> k >> x;
            add(l[k+1], x);
        }else if(op == "IR"){
            cin >> k >> x;
            add(k+1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i] ){
        printf("%d ", e[i]);
    }

}