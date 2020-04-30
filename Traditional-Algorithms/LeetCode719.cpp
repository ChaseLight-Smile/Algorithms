class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < len-1; ++i){
            int left = i + 1;
            while(left < len){
                int tmp = abs(nums[left]-nums[i]);
                ans.push_back(tmp);
                ++left;
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};

//binary search TLE 13 / 19 test cases passed.
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < len-1; ++i){
            int left = i + 1;
            while(left < len){
                int tmp = abs(nums[left]-nums[i]);
                ans.push_back(tmp);
                ++left;
            }
        }
        
        int length = ans.size();
        int left = 0 ;
        int right = length-1;
        swap(ans[left + (right-left)/2], ans[left]);
        int mid = partition(ans, left, right);
        while(true){
            if(mid == k-1){
                break;
            }else if(mid > k-1){
                mid = partition(ans, left, mid-1);
            }else{
                mid = partition(ans, mid+1, right);
            }
        }
        return ans[mid];
    }
    int partition(vector<int>& nums, int start, int end){
        int left = start; 
        int right = end;
        int key = nums[left];
        while(left < right){
            while(left < right && nums[right] >= key){
                right--;
            }
            if(left < right){
                nums[left] = nums[right];
                left++;
            }
            while(left < right && nums[left] < key){
                left++;
            }
            if(left < right){
                nums[right] = nums[left];
                right--;
            }
        }
        nums[left] = key;
        return left;
    }
};
