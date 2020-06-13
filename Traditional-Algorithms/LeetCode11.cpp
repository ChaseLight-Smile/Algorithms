class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        for(int i = 0, j = height.size()-1;i < height.size();){
            res= max(res, min(height[i], height[j])*(j-i));
            if(height[i] > height[j]) j--;
            else i++;
        }
        return res;
    }
};