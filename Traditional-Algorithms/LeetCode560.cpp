//该算法的复杂度为O(n^2)，而不是O(n^3)
class Solution {
private:
    static const int N = 20010;
    int s[N], a[N];
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i = 1; i <= nums.size(); i++){
            a[i] = nums[i-1];    //前缀和的数组下标从1开始
        }
        
        for(int i = 1; i <= nums.size(); i++){
            s[i] = s[i-1] + a[i];
        }
        
        int sum = 0;  //记录等于k的连续子数组个数，
        for(int i = 1 ; i <= nums.size(); i++){
            for(int j = i; j <= nums.size(); j++){  //这里j=i的原因是某个位置的数等于k也算
                int tmp = s[j] - s[i-1];
                if(tmp == k){
                    sum++;
                }
            }
        }
        return sum;
    }
};