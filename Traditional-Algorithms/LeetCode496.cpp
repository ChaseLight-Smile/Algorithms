class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m;
        for(int i = 0; i < nums1.size(); i++){
            m[nums1[i]] = i;
        }
        vector<int> ans(nums1.size(), -1);
        stack<int> s;
        for(int i = 0 ; i < nums2.size(); i++){
            while(!s.empty() && s.top()<nums2[i]){
                int tmp = s.top();
                s.pop();
                if(m.find(tmp) != m.end()){
                    ans[m[tmp]] = nums2[i];
                }
            }
            s.push(nums2[i]);
        }
        return ans;
    }
};


/** 
给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1。
输入格式
第一行包含整数N，表示数列长度。
第二行包含N个整数，表示整数数列。
输出格式
共一行，包含N个整数，其中第i个数表示第i个数的左边第一个比它小的数，如果不存在则输出-1。
数据范围
1≤N≤105
1≤数列中元素≤109
输入样例：
5
3 4 2 7 5
输出样例：
-1 3 -1 2 2
*/
#include <iostream>
#include <stack>
using namespace std;

const int N = 1e5+10;
int a[N], b[N];
stack<int> s;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0 ; i < n; i++){
        b[i] = -1;
    }
    if(n == 0){
        printf("-1 ");
    }
    s.push(a[0]);

    for(int i = 1; i < n; i++){
        while(!s.empty() && s.top() >= a[i]){
            s.pop();
        }
        if(!s.empty())
            b[i] = s.top();
        s.push(a[i]);
    }
    for(int i = 0 ; i < n ; i ++){
        printf("%d ", b[i]);
    }
    return 0;
}