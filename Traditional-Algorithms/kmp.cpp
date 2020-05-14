/** kmp暴力搜索匹配的字符串
给定一个模式串S，以及一个模板串P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
模板串P在模式串S中多次作为子串出现。
求出模板串P在模式串S中所有出现的位置的起始下标。
输入格式
第一行输入整数N，表示字符串P的长度。
第二行输入字符串P。
第三行输入整数M，表示字符串S的长度。
第四行输入字符串S。
输出格式
共一行，输出所有出现位置的起始下标（下标从0开始计数），整数之间用空格隔开。
数据范围
1≤N≤105
1≤M≤106
输入样例：
3
aba
5
ababa
输出样例：
0 2
*/

//方法一： 暴力匹配 超时  方法一优于方法二
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int M = 1e6+10;
char s[N], t[N];
int main(){
    int n, m;
	cin >> n >> t+1 >> m >> s+1;
    
    for(int i = 1; i <= m; i++){  //数组下标从1开始
        bool flag = true;
        for(int j = 1; j <= n; j++){
            if(s[i+j-1] != t[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d ", i-1);
        }
    }
    return 0;
}


//方法二：暴力匹配 超时
#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    string P;
    cin >> P;
    int m;
    scanf("%d", &m);
    string S;
    cin >> S;
    
    for(int i = 0; i < m; i++){   //数组下标从0开始
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(S[i+j] != P[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d ", i);
        }
    }
    return 0;
}

//方法三： 下标从1开始的kmp算法算法
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int M = 1e6+10;
char s[M], p[N];
int ne[N];
int main(){
    int n, m;
	cin >> n >> p+1 >> m >> s+1;
	
	//ne数组计算方法
	for(int i = 2, j = 0; i <= n; i++){   //p串从2开始，因为0和1的前缀和后缀是相等的，都是0，没有计算的意义
	    while(j && p[i] != p[j+1]) j = ne[j];    //一直没有匹配成功，那么搜索最长后缀串
	    if(p[i] == p[j+1]) j++;  //成功匹配
	    ne[i] = j;
	}
	
	for(int i = 1, j = 0 ; i <= m; i++){
	    while(j && s[i] != p[j+1]) j = ne[j];
	    if(s[i] == p[j+1]) j++;
	    if(j == n){
	        //成功匹配
	        printf("%d ", i - n);
	        j = ne[j];  //继续搜索其它的匹配位置
	    }
	}
	
	
    return 0;
}


//下标从0开始的KMP
#include <iostream>
using namespace std;

const int N = 1e5+10;
const int M = 1e6+10;

char s[M], p[N];
int ne[N];

int main(){
    int n, m;
	cin >> n >> p >> m >> s;
	
	//ne数组计算方法
	ne[0] = -1;
	for(int i = 1, j = -1; i < n; i++){
	    while(j != -1 && p[i] != p[j+1]) j = ne[j];
	    if(p[i] == p[j+1]) j++;
	    ne[i] = j;
	}
	
	
	for(int i = 0, j = -1 ; i < m; i++){
	    while(j != -1 && s[i] != p[j+1]) j = ne[j];
	    if(s[i] == p[j+1]) j++;
	    if(j == n-1){
	        //成功匹配
	        printf("%d ", i - n+1);
	        j = ne[j];  //继续搜索其它的匹配位置
	    }
	}
	
	
    return 0;
}