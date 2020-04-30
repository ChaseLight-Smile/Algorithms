class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> q;
        int len = stones.size();
        for (int i = 0 ; i < len; i++){
            q.push(stones[i]);
        }
        
        int first = INT_MIN;
        int second = INT_MIN;
        
        while(q.size() > 2){
            first = q.top();
            q.pop();
            second = q.top();
            q.pop();
            if(first != second){
                q.push(first-second);
            }
        }
        
        if(q.size() == 2){
            first = q.top();
            q.pop();
            second = q.top();
            q.pop();
            if(first != second){
                q.push(first-second);
                return q.top();
            }else{
                return 0;
            }
        }
        if (q.size() == 1){
            return q.top();
        }
        return 0;
    }
};