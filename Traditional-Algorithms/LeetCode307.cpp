class NumArray {
private:
    vector<int> s;
    vector<int> a;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        s = vector<int>(nums.size()+1);
        for(int i = 1; i <= nums.size(); i++){
            s[i] = s[i-1] + nums[i-1];
        }
        a = vector<int>(nums.size()+1);
        for(int i = 1; i <= nums.size(); i++){
            a[i] = nums[i-1];
        }
    }
    
    void update(int i, int val) {
        a[i+1] = val;
        for(int i = 1; i <= n; i++){
            s[i] = s[i-1] + a[i];
        }
    }
    
    int sumRange(int i, int j) {
        return s[j+1] - s[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */