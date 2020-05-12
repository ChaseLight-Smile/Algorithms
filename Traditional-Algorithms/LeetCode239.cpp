//解法一： multiset
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        
        multiset<int> s;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            s.insert(nums[i]);
        }
        auto it = s.end();
        ans.push_back(*--it);
        int left = 0;
        
        for(int i = k ; i < len; i++){
            auto pos = s.find(nums[left]);  
            s.erase(pos);
            s.insert(nums[i]);
            auto it = s.end();
            ans.push_back(*--it);
            left++;
        }
        return ans;
    }
};

//单调队列
class Solution {
private:
    static const int N = 1e5+10;
    int q[N], hh, tt = -1;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i = 0 ; i < nums.size(); i++){
            if(hh <= tt && i-k+1 > q[hh]) hh++;
            while(hh <= tt && nums[q[tt]] <= nums[i]) tt--;  //求最大值
            q[++tt] = i;
            if(i >= k-1)  ans.push_back(nums[q[hh]]);
        }
        return ans;
    }
};

//如果上述题目要同事求解滑动窗口的最大值和最小值，代码如如下：

#include <iostream>
using namespace std;

const int N = 1e6+10;
int a[N];
int q[N], hh, tt = -1;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(hh <= tt && i-k+1 > q[hh]) hh++;  //说明此时窗口已经滑出去
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;  //求最小值
        q[++tt] = i;
        if(i >= k-1) printf("%d ", a[q[hh]]);  //将打印输出的值放入到vector中
    }
    
    puts("");
    
    hh = 0, tt = -1;
    for(int i = 0; i < n; i++){
        if(hh <= tt && i-k+1 > q[hh]) hh++;  //说明此时窗口已经滑出去
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;  //求最大值
        q[++tt] = i;
        if(i >= k-1) printf("%d ", a[q[hh]]); //将打印输出的值放入到vector中
    }
    return 0;
}

