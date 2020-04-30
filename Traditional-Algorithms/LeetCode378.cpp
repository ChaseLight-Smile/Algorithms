//解法一：一开始将所有的数据都放入到priority_queue中，这导致程序的性能下降
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int x_size = matrix.size();
        int y_size = matrix[0].size();
        
        int i= 0, j = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(i = 0 ; i < x_size; i++){
            for(j =  0; j < y_size; j++){
                q.push(matrix[i][j]);
            }
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

//解法二： 全局数据排序，排序的平均时间复杂度理论上较高，但是在实际测试时发现解法二优于解法一。
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int x_size = matrix.size();
        int y_size = matrix[0].size();
        vector<int> ans;
        int i= 0, j = 0;
       
        for(i = 0 ; i < x_size; i++){
            for(j =  0; j < y_size; j++){
                ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};

//解法三： binary search AC
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int x_size = matrix.size();
        int y_size = matrix[0].size();
        vector<int> ans;
        int i= 0, j = 0;
       
        for(i = 0 ; i < x_size; i++){
            for(j =  0; j < y_size; j++){
                ans.push_back(matrix[i][j]);
            }
        }
        int length = ans.size();
        int left = 0 ;
        int right = length-1;
        swap(ans[left + (right-left)/2], ans[left]);
        int mid = partition(ans, left, right);
        while(true){
            if(mid == k-1){
                break;
            }else if(mid > k-1){
                mid = partition(ans, left, mid-1);
            }else{
                mid = partition(ans, mid+1, right);
            }
        }
        return ans[mid];
    }
    int partition(vector<int>& nums, int start, int end){
        int left = start; 
        int right = end;
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
                right--;
            }
        }
        nums[left] = key;
        return left;
    }
};

