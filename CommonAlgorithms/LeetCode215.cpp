//使用大顶堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> q;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            q.push(nums[i]);
        }
        int ans;
        while(k > 0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};

//使用小顶堆，方法更优
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            if( i < k){
                q.push(nums[i]);
            }else{
                if(nums[i] > q.top()){
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        return q.top();
    }
};

//binary search
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0){
            return -1;
        }
        int left = 0 ;
        int right = len-1;
        swap(nums[left + (right-left)/2], nums[left]);
        int mid  = find(nums,left,right);
        while(true){
            if(mid == len-k){
                break;
            }else if(mid > len-k){
                mid = find(nums, left, mid-1);
            }else{
                mid = find(nums, mid+1, right);
            }
        }
        return nums[mid];
        
    }
    int find(vector<int>& nums,int start, int end){
        int key = nums[start];
        int left = start;
        int right = end;
        while(left < right){
            while(left < right && nums[right] >= key){
                right--;
            }
            if(left < right){
                nums[left]=nums[right];
                left++;
            }
            while(left < right && nums[left] < key){
                left++;
            }
            if(left<right){
                nums[right]= nums[left];
                right--;
            }
        }
        nums[left] = key;
        return left;
    }
};