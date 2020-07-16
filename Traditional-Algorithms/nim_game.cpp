//异或为0，则先手必败；异或不为0，先手必胜
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int res = 0;
    while(n--){
        int m;
        scanf("%d", &m);
        res ^= m;
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}