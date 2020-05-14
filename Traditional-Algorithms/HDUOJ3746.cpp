#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10;
char p[N];
int ne[N];

int main(){
    int count;
    scanf("%d", &count);
    while(count--){
        cin >> p+1;
        int n = strlen(p+1);
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        int ans;
        int minloop = n - ne[n];  //最小循环节的大小
        if(ne[n] && n % minloop == 0) ans = 0;   //如果长度恰好是最小循环节的大小，说明完成循环
        else ans = minloop - ne[n]%minloop;
        printf("%d\n", ans);
    }
    return 0;
}