#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e6+10;
char p[N];
int ne[N];

int main(){
    while(~scanf("%s",p+1)){
        if(p[1] == '.'){
            break;
        }
        int n = strlen(p+1);
        //求next数组
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        
        if (ne[n] % (n - ne[n]) == 0) printf("%d\n", n / (n-ne[n]));  //这个条件就是最长前缀和最长后缀相等
		//if (n % (n - ne[n]) == 0) printf("%d\n", n / (n-ne[n]));
        else printf("1\n");
    }
    return 0;
}