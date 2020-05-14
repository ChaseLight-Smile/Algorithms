#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6+10;
char p[N];
int ne[N];

int main(){
    int n;
    int k = 1;
    scanf("%d", &n);
    while(1){
        scanf("%s", p+1);
        int n = strlen(p+1);
        for(int i = 2, j = 0; i <= n; i ++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        printf("Test case #%d\n", k);
        for(int i = 2; i <= n; i++){
            //求每个位置的循环节
            if(ne[i] && i % (i - ne[i]) == 0){  //说明此时有完整的循环节的倍数
                printf("%d %d\n", i, i/(i-ne[i]));  //2/(2-1)
            }
            
        }
        printf("\n");
        k++;
        scanf("%d", &n);
        if(n == 0){
            break;
        }
    }
    return 0;
}