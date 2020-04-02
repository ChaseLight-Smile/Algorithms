class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1_map;
        unordered_map<int, int> nums2_map;
        int nums1_len = nums1.size();
        int nums2_len = nums2.size();
        
        for(int i =  0; i < nums1_len; i++){
            nums1_map[nums1[i]] = 1;
        }
        for(int i =  0; i < nums2_len; i++){
            nums2_map[nums2[i]] = 1;
        }
        
        int min = (nums1_len < nums2_len)?nums1_len:nums2_len;
        vector<int> ans;
        if (min == nums1_len){
            for(auto & n: nums1_map){    
                if(nums2_map.find(n.first) != nums2_map.end()){
                    ans.push_back(n.first);
                }
            }
        }else{
            for(auto & n: nums2_map){    
                if(nums1_map.find(n.first) != nums1_map.end()){
                    ans.push_back(n.first);
                }
            }
        }
        return ans;
    }
};