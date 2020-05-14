#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6+10;
char p[N];
int ne[N];

int main(){
    while(scanf("%s", p+1) != -1){
        
        int n = strlen(p+1);
        for(int i = 2, j = 0; i <= n; i ++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        
        int len = n - ne[n];
        printf("%d\n", len);
    }
    return 0;
}