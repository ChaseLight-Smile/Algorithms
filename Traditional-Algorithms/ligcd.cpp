// 可以将结果变形成为扩展欧几里得算法
#include <iostream>
using namespace std;
typedef long long LL;
int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int res = exgcd(b, a%b, y, x);
    y -= (a/b) * x;
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b, m, x, y;
        scanf("%d%d%d", &a, &b, &m);
        int res = exgcd(a, m, x, y);
        if(b % res) printf("impossible\n");
        else printf("%d\n", (LL)x * (b/res) % m);
    }
    return 0;
}