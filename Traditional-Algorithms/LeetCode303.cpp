class NumArray {
    vector<int> s;
public:
    NumArray(vector<int>& nums) {
        s = vector<int>(nums.size()+1);
        for(int i = 1; i <= nums.size(); i++){
            s[i] = s[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return s[j+1] - s[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */