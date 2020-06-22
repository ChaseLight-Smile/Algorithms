// https://zh.wikipedia.org/zh-hans/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95  推导系数的过程很重要
#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int res = exgcd(b, a%b, y, x);   // 这里传参数时要交换y和x，之前传参数时是x,y
    y -= a/b * x;  // b * y + (a mod b) * x = d, a mod b = a - [a/b]*b，带入到前面的式子中，得b * y + (a - [a/b]*b)x = d, 因此 x*a +(y - [a/b]*x)b= d
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}