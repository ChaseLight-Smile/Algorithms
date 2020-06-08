//归并数组，O(m+n)时间复杂度，可以AC，但是不满足题目的时间复杂度要求
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

//递归算法，将问题转换为从小到大排列第k个数是几，那么就只要k=(m+n)/2即可
 class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total % 2 == 0){
            //说明为偶数，偶数应该取中间两个数的平均值
            int left = find(nums1, 0, nums2, 0, total/2); 
            int right = find(nums1, 0, nums2, 0, total/2+1);
            return (left+right)/2.0;
        }else{
            return find(nums1, 0, nums2, 0, total/2+1);
        }
    }
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(nums1.size()-i > nums2.size() - j) return find(nums2, j, nums1, i, k);
        if(k == 1){
            if(nums1.size() == i) return nums2[j];
            else return min(nums1[i], nums2[j]);
        }
        if(nums1.size() == i) return nums2[j + k -1];
        int si = min(i + k / 2, (int)nums1.size()), sj = j + (k - k/2);
        if(nums1[si-1] > nums2[sj-1]){
            return find(nums1, i, nums2, sj, k - (sj - j));
        }else{
            return find(nums1, si, nums2, j, k - (si - i));
        }
    }
};