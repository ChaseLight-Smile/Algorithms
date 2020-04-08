//解法一： Time limited
class KthLargest {
    priority_queue<int, vector<int>, less<int>> q;
    int count = 0;
    int k_largest;
public:
    KthLargest(int k, vector<int>& nums) {
        int len = nums.size();
        for(int i = 0 ; i< len; i++){
            q.push(nums[i]);
        }
        count = k;
        sort(nums.begin(), nums.end());
        if(len < k){
            k_largest = INT_MIN;
        }else
            k_largest = nums[len-k];
        
    }
    
    int add(int val) {
        if (val <= k_largest){
            q.push(val);
            return k_largest;
        }
        q.push(val);
        vector<int> ans;
        while(count>0){
            k_largest = q.top();
            ans.push_back(k_largest);
            q.pop();
            count--;
        }
        int ans_len = ans.size();
        for(int i = 0; i < ans_len; i++){
            q.push(ans[i]);
            count++;
        }
        return k_largest;
    }  
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */