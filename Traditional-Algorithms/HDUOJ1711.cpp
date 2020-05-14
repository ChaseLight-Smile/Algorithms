#include <iostream>
using namespace std;

const int N = 1e4+10, M = 1e6+10;
int s[M], p[N];
int ne[N];

int main(){
    int count;
    scanf("%d", &count);
    while(count--){
        int n, m;   //m为s串的长度，n为p串的长度
        scanf("%d%d", &m, &n);
        for(int i = 1; i <=m; i++){
            scanf("%d", &s[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &p[i]);
        }
        
        //求next数组
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        int i, j;
        for(i = 1, j = 0; i <= m; i++){
            while(j && s[i] != p[j+1]) j = ne[j];
            if(s[i] == p[j+1]) j++;
            if(j == n){
                //说明匹配，输出位置即可
                printf("%d\n", i-n+1);
                break;
            }
        }
        if(j != n){
            printf("-1\n");
        }
    }
}