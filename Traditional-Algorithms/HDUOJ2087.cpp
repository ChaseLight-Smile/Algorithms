#include <iostream>
#include <cstdio>
#include <cstring>

const int N = 1e3+10;
char s[N], p[N];
int ne[N];

int main(){
    while(1){
        scanf(" %s", s+1);
        if(s[1] == '#') break;
        scanf(" %s", p+1);
        int n = strlen(s+1);
        int m = strlen(p+1);
        
        for(int i = 2, j = 0; i <= m; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        
        int sum = 0;
        for(int i = 1, j = 0; i <= n; i++){
            while(j && s[i] != p[j+1]) j = ne[j];
            if(s[i] == p[j+1]) j++;
            if(j == m){
                //说明匹配
                sum++;
                j = 0;  //无重叠
            }
        }
        printf("%d\n", sum);
        
    }

    return 0;
}