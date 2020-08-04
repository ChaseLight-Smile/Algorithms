/**
给定两个长度分别为N和M的字符串A和B，求既是A的子序列又是B的子序列的字符串长度最长是多少。
输入格式
第一行包含两个整数N和M。
第二行包含一个长度为N的字符串，表示字符串A。
第三行包含一个长度为M的字符串，表示字符串B。
字符串均由小写字母构成。
输出格式
输出一个整数，表示最大长度。

数据范围
1≤N,M≤1000
输入样例：
4 5
acbd
abedc
输出样例：
3
*/


// O(n^2)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010, M = 1010;
int f[N][M];   //两维状态，表示从a序列的前i个字符，且b序列的前j个字符中得到的公共子序列，属性是这个子序列的最大值
char a[N], b[M];  //表示要寻找公共子序列的两个序列
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
			//状态转移的划分方法是判断a[i], b[j]是否包含在公共子序列中
            f[i][j] = max(f[i-1][j], f[i][j-1]);  //这里表示a[i]和b[j]中有一个不包含在子序列中
            if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);   //a[i]和b[j]相等，并且包含在公共子序列中
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}