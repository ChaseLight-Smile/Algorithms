//暴力匹配两个字符串，时间复杂度为两个字符串长度的积，多项式时间

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string s, t;
	cin >> s >> t;
	int i = 1, j = 1;
	for(; i <= s.size(); i++){
		bool flag = true;
		for(; j <= t.size(); j++){
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