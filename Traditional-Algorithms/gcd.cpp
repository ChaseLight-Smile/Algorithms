#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a%b) :a;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a,b));
    }
    return 0;
}