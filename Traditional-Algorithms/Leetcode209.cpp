/**
	Minimum Size Subarray Sum
	Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return -1 instead.

	Example
	Example 1:

	Input: [2,3,1,2,4,3], s = 7
	Output: 2
	Explanation: The subarray [4,3] has the minimal length under the problem constraint.
	Example 2:

	Input: [1, 2, 3, 4, 5], s = 100
	Output: -1
*/

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int len = nums.size();
        int i = 0, j = 0, sum = 0, ans = len + 1;
        for (;i<len;i++){
            while(j < len && sum < s){
                sum = sum + nums[j];
                j++;
            }
            if (sum >=s){
                ans = min(ans, j-i);
            }
            sum = sum - nums[i];
        }
        if (ans == len+1){
            return -1;
        }
        return ans;
    }
};