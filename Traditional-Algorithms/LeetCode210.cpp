class Solution {
private:
    static const int N = 1e5+10;
    int h[N], e[N], ne[N], idx;
    int q[N], d[N];
    int n;
public:
    vector<int> findOrder(int _n, vector<vector<int>>& g) {
        vector<int>ans;
        n = _n;
        if(g.size() == 0){
            for(int i = n-1; i >= 0;i--){
                ans.push_back(i);
            }
            return ans;
        }
        memset(h, -1, sizeof(h));
        for(int i = 0 ; i < g.size(); i++){
            add(g[i][1], g[i][0]);
            d[g[i][0]]++;
        }
        
        if(topsort()){
            for(int i = 0 ; i < n; i++){
                ans.push_back(q[i]);
            }
            return ans;
        }else return {};
    }
    
    void add(int a, int b){
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    bool topsort(){
        int hh = 0, tt = -1;
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
        }else return false;
    }
};
