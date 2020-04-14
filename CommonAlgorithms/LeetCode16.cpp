class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int min_diff = INT_MAX, closest = 0;
      for(int i = 0; i < int(nums.size()) - 2; ++i) {
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
          int sum = nums[i] + nums[left] + nums[right];
          if(abs(target - sum) < abs(min_diff)) {
            min_diff = target - sum;
            closest = sum;
          }
          if(sum < target) {
            left++;
          }else if(sum > target) {
            right--;
          }else {
            return target;
          }
        }
      }
      return closest;
    }
};