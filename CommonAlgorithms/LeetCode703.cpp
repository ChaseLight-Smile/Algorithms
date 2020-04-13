/* 采用小顶堆，那么堆顶恰好是第K大元素。如何理解？目前是求第K大元素，那么
 * 我们首先应该建立一个大小为K的最小堆，我们知道，堆顶元素一定比其他K-1个元素
 * 小，当我们继续扫描nums，然后只需要比堆顶大的时候再将数据插入到堆中，这样堆顶
 * 就会一直保存第K大元素了
*/
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int K = 0;
public:
    
    KthLargest(int k, vector<int>& nums) {
        int len = nums.size();
        if(k >= len){
            for( int  i = 0; i < len; i++){
                q.push(nums[i]);
            }
        }else{
            for(int i = 0 ; i < len; i++){
                if(i < k){
                    q.push(nums[i]);
                }else{
                    if(nums[i] > q.top()){
                        q.pop();
                        q.push(nums[i]);
                    }
                }
            }
        }
        
        K  = k;
    }
    
    int add(int val) {
        if(q.size() < K){
            q.push(val);
        }else{
            if(val > q.top()){
                q.pop();
                q.push(val);
            }
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */