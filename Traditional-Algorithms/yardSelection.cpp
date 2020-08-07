/**
在一条数轴上有 N 家商店，它们的坐标分别为 A1~AN。
现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。
输入格式
第一行输入整数N。
第二行N个整数A1~AN。
输出格式
输出一个整数，表示距离之和的最小值。
数据范围
1≤N≤100000
输入样例：
4
6 2 9 1
输出样例：
12
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n;
int a[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    int res = 0;
    for(int i = 0; i < n; i++) res += abs(a[i]- a[n/2]);
    printf("%d\n", res);
    return 0;
}