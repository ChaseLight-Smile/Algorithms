class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_nums1 = nums1.size();
        int len_nums2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i < len_nums1 && j < len_nums2){
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < len_nums1){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j < len_nums2){
            ans.push_back(nums2[j]);
            j++;
        }
        int len = ans.size();
        if (len % 2 == 0){
            int mid = (0+len-1)/2;
            return ((double)(ans[mid]+ ans[mid+1]))/2;
        }else{
            return ans[(0+len-1)/2];
        }
    }  
};