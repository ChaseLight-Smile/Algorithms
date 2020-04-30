class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size(); 
        multiset<int> s;
        vector<double> ans;
        for(int i = 0; i < k; i++){
            s.insert(nums[i]);
        }
        auto it = s.begin();
        advance(it,k/2);
        if( k%2 == 0){
            double a = *(it);
            double b = *(--it);
            ans.push_back((a+b)/2);
        }else{
            double a = *(it);
            ans.push_back(a);
        }
        int left = 0;
        
        for(int i = k ; i < len; i++){
            auto pos = s.find(nums[left]);  
            s.erase(pos);
            s.insert(nums[i]);
            auto it = s.begin();
            advance(it,k/2);
            if( k%2 == 0){
                double a = *(it);
                double b = *(--it);
                ans.push_back((a+b)/2);
            }else{
                double a = *(it);
                ans.push_back(a);
            }
                left++;
            }
        return ans;
    }
};