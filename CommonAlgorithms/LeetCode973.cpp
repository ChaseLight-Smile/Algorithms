//解法一  AC
struct queue_node{
    vector<int> node;
    double distance;
    queue_node(vector<int> a, double b): node(a), distance(b){};
};

struct cmp{
    bool operator()(queue_node* a, queue_node* b){
        return a->distance > b->distance;
    }
};

class Solution {   
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<queue_node*, vector<queue_node*>, cmp> q;
        int len = points.size();
        int i = 0;
        for( i = 0 ; i < len; i++){
            queue_node* tmp = new queue_node(points[i], sqrt(pow(points[i][0],2)+ pow(points[i][1],2)));
            q.push(tmp);
        }
        vector<vector<int>> ans;
        while(K > 0){
            ans.push_back(q.top()->node);
            q.pop();
            K--;
        }
        return ans;
    }
};