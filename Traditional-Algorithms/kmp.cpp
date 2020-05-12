//暴力匹配两个字符串，时间复杂度为两个字符串长度的积，多项式时间
/**
输入样例：
    a c f g h j y r e w x 
	f g h
输出：
    2
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6+10;
int s[N], t[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf(" %c", &s[i]);
	}
	
	for(int i = 1; i <= m; i++){
		scanf(" %c", &t[i]);
	}
	int i = 1, j = 1;
	for(; i <= n; i++){
		bool flag = true;
		for(; j <= m; j++){
			if(s[i+j-1] != t[j]){
				flag = false;
				break;
			}
		}
		if(flag == true){
			break;
		}
	}
	printf("%d", i); //输出s中匹配t字符串的起始位置
}
