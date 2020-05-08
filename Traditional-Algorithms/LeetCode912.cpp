//快速排序，该版本的代码在partition部分很清晰，能够被用在find kth element问题求解中，见LeetCode215.cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0 , nums.size()-1);
        return nums;
    }
    int partition(vector<int>& nums, int left, int right){
        int key = nums[left];
        while(left < right){
            while(left < right && nums[right] >= key){
                right--;
            }
            if(left < right){
                nums[left] = nums[right];
                left++;
            }
            while(left < right && nums[left] < key){
                left++;
            }
            if(left < right){
                nums[right] = nums[left];
            }
        }
        nums[left] = key;
        return left;
    }
    void quicksort(vector<int>& nums, int left, int right){
		if (left >= right) return;
		int p = partition(nums, left, right);
		quicksort(nums, left, p-1);
		quicksort(nums, p+1, right);
    }
};

//快速排序，这个算法不能将pivot放到正确的位置上，也就是left=right的位置不是pivot的位置,只能用作快排问题中，对find kth element没用
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        quicksort(nums, 0 , len-1);
        return nums;
    }
    void quicksort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int i = left-1;
        int j = right+1;
        int pivot = nums[left];
        while(i < j){
            do ++i; while(nums[i] < pivot);
            do --j; while(nums[j] > pivot);
            if(i < j) swap(nums[i], nums[j]);  
        }
        quicksort(nums, left, j); //注意这里选择i还是j的问题，存在边界问题
        quicksort(nums, j+1, right);
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        quicksort(nums, 0 , len-1);
        return nums;
    }
    void quicksort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int i = left-1;
        int j = right+1;
        int pivot = nums[left + (right-left)/2];
        while(i < j){
            do ++i; while(nums[i] < pivot);
            do --j; while(nums[j] > pivot);
            if(i < j) swap(nums[i], nums[j]);  
        }
        quicksort(nums, left, j);  //注意这里选择i还是j的问题，存在边界问题
        quicksort(nums, j+1, right);
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        quicksort(nums, 0 , len-1);
        return nums;
    }
    void quicksort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int i = left-1;
        int j = right+1;
        int pivot = nums[left + (right-left+1)/2]; 
        while(i < j){
            do ++i; while(nums[i] < pivot);
            do --j; while(nums[j] > pivot);
            if(i < j) swap(nums[i], nums[j]);  
        }
        quicksort(nums, left, i-1);  //注意这里选择i还是j的问题，存在边界问题
        quicksort(nums, i, right);
    }
};

//堆排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>q;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            q.push(nums[i]);
        }
        nums.clear();
        while(!q.empty()){
            int tmp = q.top();
            nums.push_back(tmp);
            q.pop();
        }
        return nums;
    }
};


//归并排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        vector<int> ans = mergeSort(nums, 0, nums.size()-1);
        return ans;
    }
    vector<int> mergeSort(vector<int>& nums, int left, int right){
        if(left == right){
            return {nums[left]};
        }else if(left+1 == right){
            if(nums[left] >= nums[right]){
                return {nums[right], nums[left]};
            }else
                return {nums[left], nums[right]};
        }else if(left < right){
            int mid = left + (right-left)/2;
            vector<int> leftNums = mergeSort(nums, left, mid);
            vector<int> rightNums = mergeSort(nums, mid+1, right);
            vector<int> ans = merge(leftNums, rightNums);
            return ans;
        }
        return {};
    }
    
    vector<int> merge(vector<int> nums1, vector<int> nums2){
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
        return ans;
    }
    
};