#include <iostream>
#include <string>
using namespace std;

const int N = 1e4+10, M = 1e6+10;
char p[N], s[M];
int ne[N];
int main(){
    int k;
    scanf("%d", &k);
    while(k--){
        string a, b;
        cin >> a >> b;
        int n = a.size();  //p串
        int m = b.size();
        for(int i = 1 ; i <= n; i++){
            p[i] = a[i-1];
        }
        for(int i = 1 ; i <= m; i++){
            s[i] = b[i-1];
        }
        
        int sum = 0;
    
        //求next数组
        for(int i =2 , j = 0; i <= n; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        
        for(int i = 1, j=0; i <= m; i++){
            while(j && s[i] != p[j+1]) j = ne[j];
            if(s[i] == p[j+1]) j++;
            if(j == n){
                sum++;
                j = ne[j];
            }
        }
        printf("%d\n", sum);
    }
    
   
    
    return 0;
}