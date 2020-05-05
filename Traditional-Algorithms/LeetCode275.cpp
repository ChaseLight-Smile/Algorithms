class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int right = citations.size();
        while(left < right){
            int mid = left + right + 1 >> 1;
            if(citations[citations.size()-mid] >= mid){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
};