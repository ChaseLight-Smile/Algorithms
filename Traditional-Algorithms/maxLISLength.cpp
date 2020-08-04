/**
给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。
输入格式
第一行包含整数N。
第二行包含N个整数，表示完整序列。
输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤100000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/

//我们看到本题的数据范围为1e5，如果采用DP方法，则时间复杂度为1e10，一定会TLE，这里采用贪心方法
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];
int q[N];  //所有不同长度的子序列的结尾的最小值
int n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int len = 0;
    for(int i = 1; i <= n; i++){
        int l = 0, r = len;
		//通过二分检索寻找一个位置，这个位置应该放入a[i]，并且是当前的小于a[i]的最大值之后，使得整个q数组单调递增，并且增长最慢
        while(l < r){
            int mid = l + r + 1>> 1;
            if(q[mid] < a[i]) l = mid;
            else r = mid-1;
        }
        len = max(len, r + 1);   //更新当前的单调递增序列的最大长度
        q[r + 1] = a[i];  //将a[i]插入到q中
    }
    printf("%d\n", len);
    return 0;
}