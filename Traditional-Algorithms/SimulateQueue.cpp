/**  数组模拟队列
实现一个队列，队列初始为空，支持四种操作：
(1) “push x” – 向队尾插入一个数x；
(2) “pop” – 从队头弹出一个数；
(3) “empty” – 判断队列是否为空；
(4) “query” – 查询队头元素。
现在要对队列进行M个操作，其中的每个操作3和操作4都要输出相应的结果。
输入格式
第一行包含整数M，表示操作次数。
接下来M行，每行包含一个操作命令，操作命令为”push x”，”pop”，”empty”，”query”中的一种。
输出格式
对于每个”empty”和”query”操作都要输出一个查询结果，每个结果占一行。
其中，”empty”操作的查询结果为“YES”或“NO”，”query”操作的查询结果为一个整数，表示队头元素的值。
数据范围
1≤M≤100000,
1≤x≤109,
所有操作保证合法。
输入样例：
10
push 6
empty
query
pop
empty
push 3
push 4
pop
query
push 6
输出样例：
NO
6
YES
4
*/
#include <iostream>
using namespace std;

const int N = 1e5+10;

int q[N], hh, tt = -1;

void q_push(int x){
    q[++tt] = x;
}

void q_pop(){
    hh++;
}

bool q_empty(){
    if(hh > tt){
        return true;
    }
    return false;
}

int q_query(){
    return q[hh];
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        string op;
        cin >> op;
        int x;
        if(op == "push"){
            cin >> x;
            q_push(x);
        }else if(op == "pop"){
            q_pop();
        }else if(op == "empty"){
            if(q_empty()) printf("YES\n");
            else printf("NO\n");
        }if (op == "query"){
            printf("%d\n", q_query());
        }
    }
    return 0;
}