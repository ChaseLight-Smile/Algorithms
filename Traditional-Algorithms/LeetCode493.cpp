//mergesort的应用 O(nlogn)
class Solution {
private:
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
    }
    
    int mergesort(vector<int>& nums, int l, int r){
        if(l >= r) return 0;
        int mid = l + ((r-l) >> 1);
        int res = mergesort(nums, l, mid) + mergesort(nums, mid+1, r);
        int i = l, j = mid+1, k = 0, p = mid+1;
        vector<int> ans(r-l+1);
        while(i <= mid){
            while(p <= r && nums[i] > (long)2 * nums[p]){  //类型需要提升到long，因为nums[p]可能为2^32-1，左移一位会超出范围
                ++p;
            }
            res += p-(mid+1);
            while(j <= r && nums[i] >= nums[j]) ans[k++] = nums[j++];
            ans[k++] = nums[i++];
        }
        while(j <= r) ans[k++] = nums[j++];
        for(int i = l , j = 0; i <= r; i++, j++) nums[i] = ans[j];
        return res;
    }
};

/**变形题
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > k*nums[j] (a<=k<=b)
You need to return the number of important reverse pairs in the given array.
此时只需要将上题中的2换掉，并且数字范围可能会提升到long long
*/