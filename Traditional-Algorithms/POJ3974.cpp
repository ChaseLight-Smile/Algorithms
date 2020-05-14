#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2e6+10;
char p[N], Ma[2*N];
int Mp[2*N];

int main(){
    int res = 1;
    scanf("%s",p);
    while(1){
        int l = 0;
        int n = strlen(p);
        Ma[l++] = '$';
        Ma[l++] = '#';
        for(int i = 0; i < n; i++){
            Ma[l++] = p[i];
            Ma[l++] = '#';
        }
        Ma[l] = 0;
        int mx = 0, id = 0;
        for(int i = 0 ; i < l; i++){
            Mp[i] = mx > i? min(Mp[2*id-i],mx-i):1;
            while(Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;
            if(i+ Mp[i] > mx){
                mx = i + Mp[i];
                id = i;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 2*n+2; i++){
            ans= max(ans, Mp[i] - 1);
        }
        printf("Case %d: %d\n", res++, ans);
        scanf("%s",p);
        if(strcmp(p, "END") == 0) {
            break;
        }
    }
    return 0;
}