//解法一： hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            m[nums[i]] = i;
        }
        vector<int>ans;
        for(int i = 0 ; i < len; i++){
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};

//解法一的改进版，将插入到hash表的操作和寻找目标位置的操作合二为一
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++){
            int v = target - nums[i];
            if(m.find(v) != m.end()){    //每一步都在检查hash表中是否存在target-当前值，如果存在输出其对应的下标即可。
                return {m[v], i};
            }
            m[nums[i]] = i; 
        }
        return {};
    }
};


//解法二：loop
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans;
        bool flag = false;
        for(int i = 0 ; i < len; i++){
            for(int j = i; j < len; j++){
                if(nums[i] + nums[j] == target && i != j){
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }
            if (flag == true){
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for(int i = 0; i<len-1;i++){
            int left = i+1;
            while(left < len){
                if(nums[i] + nums[left] == target){
                    return {i,left};
                }else if(nums[i] + nums[left] < target){
                    left++;
                    continue;
                }
                left++;
            }
        }
        return {-1,-1};
    }
};


/** 变形题 题目来自POJ
给定两个升序排序的有序数组A和B，以及一个目标值x。数组下标从0开始。
请你求出满足A[i] + B[j] = x的数对(i, j)。

数据保证有唯一解。

输入格式
第一行包含三个整数n，m，x，分别表示A的长度，B的长度以及目标值x。

第二行包含n个整数，表示数组A。

第三行包含m个整数，表示数组B。

输出格式
共一行，包含两个整数 i 和 j。

数据范围
数组长度不超过100000。
同一数组内元素各不相同。
1≤数组元素≤10的9次方
输入样例：
4 5 6
1 2 4 7
3 4 6 8 9
输出样例：
1 1
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n , m , x;
    scanf("%d%d%d", &n, &m, &x);
    vector<int> a(n);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
    }
    vector<int> b(m);
    for(int i = 0 ; i < m; i++){
        scanf("%d", &b[i]);
    }
    
    for(int i = 0, j = m-1; i < n, j >=0;){
        if(a[i] + b[j] == x){
            printf("%d %d", i , j);
            break;
        }else if(a[i] + b[j] > x){
            j--;
        }else{
            i++;
        }
    }
    return 0;
}