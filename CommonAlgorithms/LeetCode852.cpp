class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        int ans;
        for(int i = 0 ; i < len; i++){
            if(A[i] < A[i+1]){
                continue;
            }else{
                ans = i ;
                break;
            }
        }
        return ans;
    }
};