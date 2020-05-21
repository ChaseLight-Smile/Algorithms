class Solution {
private:
    static const int N = 1e5+10;
    int h[N], e[N], ne[N], idx;
    int q[N], d[N];
    int n;
public:
    bool canFinish(int _n, vector<vector<int>>& nums) {
        if(nums.size() == 0){
            return true;
        }
        memset(h, -1, sizeof h);
        n = _n;
        for(int i = 0 ; i < nums.size(); i++){
            add(nums[i][0], nums[i][1]);
            d[nums[i][1]]++;
        }
        
        if(topsort()){
            return true;
        }else return false;
        
    }
    void add(int a , int b){
        e[idx] = b;
        ne[idx] =  h[a];
        h[a] = idx++;
    } 
    bool topsort(){
        int hh = 0, tt=-1;
        for(int i = 0 ; i < n; i++){
            if(!d[i]){
                q[++tt] = i;
            }
        }
        while(hh <= tt){
            int u = q[hh++];
            for(int i = h[u]; i != -1; i = ne[i]){
                int j = e[i];
                d[j]--;
                if(!d[j]){
                    q[++tt] = j;
                }
            }
        }
        if(tt == n-1){
            return true;
        }
        return false;
    }
};