#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5+10;

int p[N], Ma[2*N], Mp[2*N];

int main(){
    int count;
    scanf("%d", &count);
    while(count--){
        int n;
        scanf("%d", &n);
        for(int i = 0 ; i < n; i ++){
            scanf("%d", &p[i]);
        }
        
        int l = 0;
        Ma[l++] = -100;
        Ma[l++] = 0;
        for(int i = 0 ; i < n; i ++){
            Ma[l++] = p[i];
            Ma[l++] = 0;
        }
        Ma[l] = 0;
        int mx = 0 , id = 0;
        for(int i = 0 ; i < l; i++){
            Mp[i] = mx > i? min(Mp[2*id-i],mx-i):1;
            while(Ma[i+Mp[i]] == Ma[i-Mp[i]] && Ma[i-Mp[i]] <= Ma[i-Mp[i]+2]) Mp[i]++;  //Ma[i-Mp[i]] <= Ma[i-Mp[i]+2]保证了严格的单调递减特性
            if(i + Mp[i] > mx){
                mx = i + Mp[i];
                id = i;
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < 2*n +2; i++){
            ans = max(ans, Mp[i] - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}