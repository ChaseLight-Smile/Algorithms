class Solution {
private:
    static const int N = 110, M = 1e5+10;
    struct{
        int a, b, w;
    }edge[M];
    int n, m, k;
    int dist[N], backup[N];
    int src;
    
public:
    int findCheapestPrice(int _n, vector<vector<int>>& flights, int _src, int dst, int K) {
        n = _n;
        m = flights.size();
        k = K;
        src = _src;
        
        for(int i = 0 ; i < flights.size(); i++){
            edge[i] = {flights[i][0], flights[i][1], flights[i][2]};
        }
        
        bellman_ford();
        
        if(dist[dst] > 0x3f3f3f3f / 2){
            return -1;
        }
        return dist[dst];
    }
    
    void bellman_ford(){
        memset(dist, 0x3f, sizeof dist);
        dist[src] = 0;
        
        for(int i = 0; i < k+1; i++){
            memcpy(backup, dist, sizeof dist);
            for(int j = 0 ; j < m; j++){
                int a = edge[j].a, b = edge[j].b, w= edge[j].w;
                dist[b] = min(dist[b], backup[a] + w);
            }
        }
    }
};