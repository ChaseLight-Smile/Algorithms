class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>A, B;
        for(int i = num1.size()-1; i >= 0; i--){
            A.push_back(num1[i] - '0');
        }
        for(int i = num2.size()-1; i >= 0; i--){
            B.push_back(num2[i] - '0');
        }
        
        auto C = mul(A, B);
        string ans;
        for(int i = C.size()-1; i >= 0; i--){
            ans += to_string(C[i]);
        }
        return ans;
    }
    vector<int> mul(vector<int>& A, vector<int>& B){
        vector<int> C;
        for(int i = 0; i < B.size(); i++){
            int t = 0;
            vector<int> tmp;
            for(int k = 0; k < i; k++){
                tmp.push_back(0);
            }
            for(int j = 0; j < A.size(); j++){
                tmp.push_back((B[i]*A[j]+ t)%10);
                t = (B[i]*A[j]+t)/10;
            }
            if(t) tmp.push_back(t);
            auto D = add(C, tmp);
            C = D;
        }
        //去掉前导0
        while(C.size() > 1 && C.back() == 0) C.pop_back();
        return C;
    }
    vector<int> add(vector<int>& A, vector<int>& B){
        //实现加法，用于计算每个因子的和
        vector<int> C;
        int t = 0;
        for(int i = 0; i < A.size() || i < B.size(); i++){
            if(i < A.size()) t += A[i];
            if(i < B.size()) t += B[i];
            C.push_back(t % 10);
            t = t / 10;
        }
        if(t) C.push_back(1);
        return C;
    }
};

/**
高精度乘法变形
题目出自：POJ
给定两个正整数A和B，请你计算A * B的值。

输入格式
共两行，第一行包含整数A，第二行包含整数B。

输出格式
共一行，包含A * B的值。

数据范围
1≤A的长度≤100000,
0≤B≤10000
输入样例：
4
5
输出样例：
20
Note：在计算结果中，不能出现任何的前导0。以下代码为本题的题解。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int>& A, int b){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || t; i++){
        if(i < A.size()) t += A[i]*b;
        C.push_back(t%10);
        t /= 10;
    }
    //去掉前导0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}


int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for(int i = a.size()-1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }
    
    auto C = mul(A, b);
    
    for(int i = C.size()-1; i >= 0; i--){
        printf("%d", C[i]);
    }
    return 0;
}