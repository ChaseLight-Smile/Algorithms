//poj 1503是一个大整数加法的变形题，在C++中不支持大整数，java和python都支持  HDUOJ1002大整数加法
class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int>A, B;
        for(int i = num1.size()-1; i >= 0 ; i--){
            A.push_back(num1[i] - '0');
        }
        for(int i = num2.size()-1; i >= 0; i--){
            B.push_back(num2[i] - '0');
        }
        auto C = add(A, B);
        string ans;
        for(int i = C.size()-1; i>= 0; i--){
            ans += to_string(C[i]);
        }
        return ans;
    }
    
    vector<int> add(vector<int>& A, vector<int>& B){
        vector<int> C;
        int t = 0;
        for(int i = 0; i < A.size() || i < B.size(); i++){
            if(i < A.size()) t += A[i];
            if(i < B.size()) t += B[i];
            C.push_back(t%10);
            t /= 10;
        }
        if(t) C.push_back(1);
        return C;
    }
};

/**
  * 变形题：
  * 给定两个正整数，计算它们的差，计算结果可能为负数。
  * 输入样例：
        123
		121
	输出2，看清楚是2，不是002
	    55
		33
	输出是22

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool cmp(vector<int>& A, vector<int>& B){
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i--){
        //从高位开始比较
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;// 如果上述循环全部执行完没有return，说明A和B相等，在这里我们返回true
}

vector<int> sub(vector<int>& A, vector<int>& B){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t+10)%10);
        if(t >= 0) t = 0;
        else t = 1;
    }
    //55-50 = 5 但是我们的算法在这之前会返回05， 应该将前导0去掉
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size()-1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }
    for(int i = b.size()-1; i >= 0; i--){
        B.push_back(b[i] - '0');
    }
    
    if(cmp(A, B)){
        //要求A>B，始终只做大的数减去小的数，减少处理边界问题
        auto C = sub(A, B);
        for(int i = C.size()-1; i >= 0; i--){
            printf("%d", C[i]);
        }
    }else{
        auto C = sub(B, A);
        printf("-");
        for(int i = C.size()-1; i >= 0; i--){
            printf("%d", C[i]);
        }
    }
}