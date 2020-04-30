class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> nums1_map;
        unordered_map<int,int> nums2_map;
        int nums1_len = nums1.size();
        int nums2_len = nums2.size();
        for(int i = 0 ; i < nums1_len ; i++){
            if(nums1_map.find(nums1[i]) != nums1_map.end()){
                nums1_map[nums1[i]] = nums1_map[nums1[i]] + 1;
            }else
                nums1_map[nums1[i]] = 1;
        }
        
        for(int i = 0 ; i < nums2_len ; i++){
            if(nums2_map.find(nums2[i]) != nums2_map.end()){
                nums2_map[nums2[i]] = nums2_map[nums2[i]] + 1;
            }else
                nums2_map[nums2[i]] = 1;
        }
        
        
        int min = 0;
        
        for(auto & n : nums1_map){
            if(nums2_map.find(n.first) != nums2_map.end()){
                if (n.second >= nums2_map[n.first]){
                    min = nums2_map[n.first];
                    while(min > 0){
                        ans.push_back(n.first);
                        min--;
                    }
                }else{
                    if (n.second < nums2_map[n.first]){
                    min = nums1_map[n.first];
                    while(min > 0){
                        ans.push_back(n.first);
                        min--;
                    }
                }
            }
            }
        }        
        return ans;
    }     
};