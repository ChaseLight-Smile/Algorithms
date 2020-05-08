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

//很简练的快排模板
#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int>& nums, int left, int right){
    if(left >= right) return;
    int i = left - 1;
    int j = right + 1;
    int pivot = nums[left + right + 1 >> 1];
    while(i < j){
        do ++i; while(nums[i] < pivot);
        do --j; while(nums[j] > pivot);
        if(i < j) swap(nums[i], nums[j]);
    }
    quicksort(nums, left, i-1);
    quicksort(nums, i, right);
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int>nums(n);
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    quicksort(nums, 0 , n-1);
    for(int i = 0; i< n; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}

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

//merge sort  AC 速度不如快排，快排内存排序之王。
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0 , nums.size()-1);
        return nums;
    }
    
    void mergesort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = l + r >> 1;
        mergesort(nums, l, mid), mergesort(nums, mid+1, r);
        int i = l, j = mid+1, k = 0;
        vector<int>ans(r-l+1);   //这里如果ans(nums.size()) 代码通不过，特别注意
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                ans[k++] = nums[i++];
            }else
                ans[k++] = nums[j++];
        }
        while(i <= mid){
            ans[k++] = nums[i++];
        }
        while(j <= r){
            ans[k++] = nums[j++];
        }
        for(int i = l, j = 0; i <= r; i++, j++){
            nums[i] = ans[j];
        }    
    }
};