/**
输入一个包含n个方程n个未知数的线性方程组。
方程组中的系数为实数。
求解这个方程组。

输入格式
第一行包含整数n。
接下来n行，每行包含n+1个实数，表示一个方程的n个系数以及等号右侧的常数。
输出格式
如果给定线性方程组存在唯一解，则输出共n行，其中第i行输出第i个未知数的解，结果保留两位小数。
如果给定线性方程组存在无数解，则输出“Infinite group solutions”。
如果给定线性方程组无解，则输出“No solution”。
数据范围
1≤n≤100,
所有输入系数以及常数均保留两位小数，绝对值均不超过100。
输入样例：
3
1.00 2.00 -1.00 -6.00
2.00 1.00 -3.00 -9.00
-1.00 -1.00 2.00 7.00
输出样例：
1.00
-2.00
3.00
*/


#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];  //系数矩阵

int gauss(){
    int c, r; // c表示当前枚举到哪一列，r表示当前枚举到哪一行
    for(c =0, r = 0; c < n; c++){
        int t = r;
        for(int i = r; i < n; i++){
            if(fabs(a[i][c]) > fabs(a[t][c])){
                t = i;   //找出不同行中当前列上的最大值，该步骤为了保证除法计算之后的精度
            }
        }
        
        if(fabs(a[t][c]) < eps) continue;  //说明这个位置已经为0
        
        for(int i = c; i < n+1; i++) swap(a[t][i], a[r][i]); //交换主元行
        for(int i = n; i >= c; i--) a[r][i] /= a[r][c];  //将主元变成1
        for(int i = r + 1; i < n; i++){
            if(fabs(a[i][c]) > eps){  //说明主元下方元素不为0
                for(int j = n; j >= c; j--){
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }
    
    if(r < n){
        for(int i = r; i < n; i++){
            if(fabs(a[i][n]) > eps){
                return 2;   //不存在解
            }
        }
        return 1;  //存在无穷多组解
    }
    
    //倒着消元，每一列只存在主元
    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    
    return 0; // 说明有唯一解
    
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n+1; j++){
            cin >> a[i][j];
        }
    }
    int res = gauss();
    if(res == 0){
        for(int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
    }else if(res == 1) puts("Infinite group solutions");
    else puts("No solution");
    return 0;
}