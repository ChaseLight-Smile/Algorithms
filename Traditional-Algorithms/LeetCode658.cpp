struct queue_node{
    int node;
    int diff;
    queue_node(int n, int d):node(n), diff(d){};
};

struct cmp{
    bool operator()(queue_node* a, queue_node* b){
        return a->diff < b->diff; //max_heap
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        priority_queue<queue_node*, vector<queue_node*>, cmp> q;
        int count = 0;
        for(int i = 0; i < len; i++){
            if(count < k){
                queue_node* tmp = new queue_node(arr[i],abs(arr[i]-x));
                q.push(tmp);
            }else{
                if(q.top()->diff > abs(arr[i]-x)){
                    q.pop();
                    queue_node* tmp = new queue_node(arr[i],abs(arr[i]-x));
                    q.push(tmp);
                }
            }
            count++;
        }
        vector<int>ans;
        while(q.size() > 0){
            ans.push_back(q.top()->node);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};