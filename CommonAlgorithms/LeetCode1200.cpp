class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minimum = INT_MAX;
        int len = arr.size();
        for(int i = 0; i < len-1; i++){
            for(int j = i+1; j < len; j++){
                int diff = abs(arr[j]-arr[i]);
                if(diff < minimum){
                    minimum = diff;
                }else{
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < len-1; i++){
            int nNum = binarySearch(arr, i+1, len-1, arr[i] + minimum);
            int pNum = binarySearch(arr, i+1, len-1, arr[i] - minimum);
            if(nNum != INT_MIN){
                ans.push_back({arr[i], nNum});
            }
            if(pNum != INT_MIN){
                ans.push_back({arr[i], pNum});
            }
        }
        return ans;
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left < right){
            int mid = left +(right-left+1)/2;
            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(target == nums[left]){
            return nums[left];
        }
        return INT_MIN;
    }
};