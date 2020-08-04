/**
给定两个字符串A和B，现在要将A经过若干操作变为B，可进行的操作有：
删除–将字符串A中的某个字符删除。
插入–在字符串A的某个位置插入某个字符。
替换–将字符串A中的某个字符替换为另一个字符。
现在请你求出，将A变为B至少需要进行多少次操作。
输入格式
第一行包含整数n，表示字符串A的长度。
第二行包含一个长度为n的字符串A。
第三行包含整数m，表示字符串B的长度。
第四行包含一个长度为m的字符串B。
字符串中均只包含大写字母。
输出格式
输出一个整数，表示最少操作次数。

数据范围
1≤n,m≤1000
输入样例：
10 
AGTCTGACGC
11 
AGTAAGTAGGC
输出样例：
4
*/


// O(n^2)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
char a[N], b[N];
int f[N][N];   //表示字符串a[1~i]变成b[1~j]的操作方式，属性是这些操作的最小值
int n, m;

int main(){
    scanf("%d%s", &n, a+1);
    scanf("%d%s", &m, b+1);
    for(int i = 0; i <= n; i++) f[i][0] = i;  //初始化边界，当b为空时，也是只能添加a或者删除b来使得二者相等
    for(int i = 0; i <= m; i++) f[0][i] = i;   //初始化边界，如果a字符串为空，那么想要和b字符串相等，只能添加a或者删除b
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[i][j] = min(f[i-1][j] + 1, f[i][j-1]+1);   //删除a或者b中多余的字符
            if(a[i] == b[j]) f[i][j] = min(f[i][j], f[i-1][j-1]); //最后一个字符相等
            else f[i][j] = min(f[i][j], f[i-1][j-1]+1);  //最后一个字符不相等
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}