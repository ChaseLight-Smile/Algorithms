//hash table
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        int len = nums.size();
        for(int i = 0 ; i< len;i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]] = m[nums[i]]+1;
            }else{
                m[nums[i]] = 1;
            }
        }
        int ans ;
        for(auto &n : m){
            if(n.second != 1){
                ans = n.first;
            }
        }
        return ans;
    }
};


//二分
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 0 ;
        int right = len-1;
        while(left < right){
            int mid = left + (right - left)/2;
            
            int count = 0;
            
            for(auto & n : nums){
                if(n <= mid){
                    count++;
                }
            }
            
            if(count > mid){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};

//cyclic sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while(i < len){
            int j = nums[i];
            if(j < len && nums[i] != nums[j-1]){
                swap(nums[i], nums[j-1]);
            }else{
                ++i;
            }
        }
        for(auto & n : nums){
            cout << n << " ";
        }
        int ans = -1;
        for(int i = 0; i < len; i++){
            if(nums[i] != i+1){
                ans = i;
                break;
            }
        }
        return nums[ans];
    }
};

//快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int slow = nums[0] ;
        int fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                fast = nums[0];
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return -1;
    }
};