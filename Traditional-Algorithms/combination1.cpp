/**
给定n组询问，每组询问给定两个整数a，b，请你输出Cba mod (109+7)的值。
输入格式
第一行包含整数n。
接下来n行，每行包含一组a和b。
输出格式
共n行，每行输出一个询问的解。
数据范围
1≤n≤10000,
1≤b≤a≤2000
输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1
*/

//时间复杂度为O(n^2)
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2010, mod = 1e9+7;
int n;
int combination[N][N];

//先将每个结果保存好，之后直接取值即可
void init(){
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(!j) combination[i][j] = 1;
            else combination[i][j] = (combination[i-1][j] + combination[i-1][j-1]) % mod;
        }
    }
}

int main(){
    init();
    scanf("%d", &n);
    while(n--){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", combination[a][b]);
    }
    return 0;
}

