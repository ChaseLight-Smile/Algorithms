#include <iostream>
using namespace std;

int n, m;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= n / i; i ++){
        if(n % i == 0) return false;
    }
    return true;
}


int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        if(isPrime(m)){
            printf("Yes\n");
        }else printf("No\n");
    }
}