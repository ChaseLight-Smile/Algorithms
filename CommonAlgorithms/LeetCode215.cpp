//使用大顶堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> q;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            q.push(nums[i]);
        }
        int ans;
        while(k > 0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};

//使用小顶堆，方法更优
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            if( i < k){
                q.push(nums[i]);
            }else{
                if(nums[i] > q.top()){
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        return q.top();
    }
};