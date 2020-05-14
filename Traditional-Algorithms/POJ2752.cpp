#include <iostream>
#include <cstring>
using namespace std;

const int N = 4e5+10;
char p[N];
int ne[N];
int ans[N];

int main(){
    while(scanf("%s", p+1) != EOF){
        int n = strlen(p+1);
        for(int i = 2, j = 0; i <= n; i ++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        int t = ne[n];
        int cnt = 0;
		while (t != 0)
		{
			ans[cnt++] = t;
			t = ne[t];
		}
		for (int i = cnt - 1; i >= 0; --i)
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", n);

    }
    return 0;
}