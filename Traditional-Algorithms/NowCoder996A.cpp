#include <iostream>
using namespace std;
typedef long long LL;

//计算a ^ k % p
int qmi(int a, int k, int p){
    int res= 1 % p;   //为什么这里要1 % p;
    while(k){
        if(k & 1) res = (LL)res * a % p;
        a = (LL) a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    int a, b, p;
    scanf("%d%d%d", &a, &b, &p);
    printf("%d\n", qmi(a, b, p));
    return 0;
}