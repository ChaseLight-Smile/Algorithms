//解法一  min_heap
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

//解法二 max_heap
struct queue_node{
    vector<int> node;
    double distance;
    queue_node(vector<int> a, double b): node(a), distance(b){};
};

struct cmp{
    bool operator()(queue_node* a, queue_node* b){
        //return a->distance > b->distance;   //min_heap
        return a->distance < b->distance;  //max_heap
    }
};

class Solution {   
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<queue_node*, vector<queue_node*>, cmp> q;
        int len = points.size();
        int i = 0;
        for( i = 0 ; i < K; i++){
            queue_node* tmp = new queue_node(points[i], sqrt(pow(points[i][0],2)+ pow(points[i][1],2)));
            q.push(tmp);
        }
        
        while(i < len){
            queue_node* tmp = new queue_node(points[i], sqrt(pow(points[i][0],2)+ pow(points[i][1],2)));
            if (tmp->distance < q.top()->distance){
                q.pop();
                q.push(tmp);
            }
            i++;
        }
        
        vector<vector<int>> ans;
        while(q.size()>0){
            ans.push_back(q.top()->node);
            q.pop();
        }
        return ans;
    }
};