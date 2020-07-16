/**
给定一个整数n和m个不同的质数p1,p2,…,pm。
请你求出1~n中能被p1,p2,…,pm中的至少一个数整除的整数有多少个。
输入格式
第一行包含整数n和m。

第二行包含m个质数。

输出格式
输出一个整数，表示满足条件的整数的个数。

数据范围
1≤m≤16,
1≤n,pi≤109
输入样例：
10 2
2 3
输出样例：
7
*/


#include <iostream>
using namespace std;

typedef long long LL;
const int N = 20;
int n, m ;
int prime[N];

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        cin >> prime[i];
    }
    int res = 0;
    for(int i = 1; i < 1 << m; i++){
        int t = 1, cnt = 0;  //t表示当前所有质数的乘积，cnt表示当前选法包含几个1
        for(int j = 0; j < m; j++){ //判断到底当前哪个质数或者哪些质数的组合被选择了，比如测试用例中，
            if(i >> j & 1){
                cnt++;
                if((LL)t * prime[j] > n){
                    t = -1;
                    break;
                }
                t *= prime[j];
            }
        }
        if(t != -1){  //这里是确定符号位
            if(cnt%2) res += n/t;
            else res -= n/t;
        }
    }
    cout << res  << endl;
    return 0;
}