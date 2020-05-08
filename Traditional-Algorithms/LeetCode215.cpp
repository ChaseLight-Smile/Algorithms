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
        int mid  = partition(nums,left,right);
        while(true){
            if(mid == len-k){
                break;
            }else if(mid > len-k){
                mid = partition(nums, left, mid-1);
            }else{
                mid = partition(nums, mid+1, right);
            }
        }
        return nums[mid];
        
    }
    int partition(vector<int>& nums,int start, int end){
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


//使用快速选择算法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       return quicksort(nums, 0, nums.size()-1, k);
    }
    int quicksort(vector<int>& nums, int l, int r, int k){
        if(l == r){
            return nums[l];
        }
        int pivot = nums[l];
        int i = l-1;
        int j = r+1;
        while(i < j){
            do ++i; while(nums[i] > pivot);  //注意这里是从大到小排序
            do --j; while(nums[j] < pivot);
            if(i < j) swap(nums[i], nums[j]);
        }
        int sl = j - l + 1;
        if(k <= sl){
            return quicksort(nums, l, j, k);
        }
        return quicksort(nums, j+1, r, k-sl);
    }
};

//求第k小数的算法，也是使用快速选择算法
#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int quicksort(int left, int right, int k){
    if(left == right) return nums[left];
    int i = left-1;
    int j = right+1;
    int pivot = nums[left];
    while(i < j){
        do ++i; while(nums[i] < pivot);
        do --j; while(nums[j] > pivot);
        if(i < j) swap(nums[i],nums[j]);
    }
    int sl = j-left+1;
    if(k <= sl){
        return quicksort(left, j, k);
    }
    return quicksort(j+1, right, k-sl);
}

int main(){
    int n , k;
    cin >> n >> k;
    nums = vector<int>(n);
    for(int i = 0 ; i < n; ++i){
        scanf("%d", &nums[i]);
    }
    cout << quicksort(0, n-1, k) << endl;
    
    return 0;
}