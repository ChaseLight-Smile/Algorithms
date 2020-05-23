class Solution {
private:
    static const int N = 110, M = 1e4+10; //从这里看出，这个图是一个稠密图，应该用矩阵存储比较好
    struct{
        int a, b, w;  
    }edge[M];
    int dist[N], backup[N];
    int n, m, k;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        for(int i = 0 ; i < times.size(); i++){
            edge[i] = {times[i][0], times[i][1], times[i][2]};
        }
        n = N, m = times.size(), k = K;
        bellman_ford();
        int maximum = 0;
        for(int i = 1 ; i <= n; i++){
            if(dist[i] >= 0x3f3f3f3f / 2) return -1;
            maximum = max(maximum, dist[i]);
        }
        return maximum;
    }
    void bellman_ford(){
        memset(dist, 0x3f, sizeof dist);
        dist[k] = 0;
        
        // for(int i = 0; i < n; i++){   //迭代点的个数次，表示最短路径中最多经过n条边，实际上到n-1即可，该条件从题目中抽象出来，是bellman-ford算法比较难的部分
        for(int i = 0; i < n-1; i++){   //迭代点的个数次，表示最短路径中最多经过n条边，实际上到n-1即可
            memcpy(backup, dist, sizeof dist);   //无记忆化操作
            for(int j = 0; j < m; j++){
                int a = edge[j].a, b = edge[j].b, w = edge[j].w;
                dist[b] = min(dist[b], backup[a] + w);    //无记忆松弛
            }
        }
    }
};


//朴素dijkstra算法
class Solution {
private:
    static const int N = 110, M = 1e5+10;
    int g[N][N];
    int dist[N];
    int n, k;
    bool visited[N];
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        memset(g, 0x3f, sizeof(g));  //记住这里一定要对二维矩阵初始化，否则所有的矩阵两点间距离都为0
        for(int i = 0; i < times.size(); i++){
            g[times[i][0]][times[i][1]] = times[i][2];
        }
        n = N, k = K;
        dijkstra();
        int maximum = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 0x3f3f3f3f) return -1;
            maximum = max(maximum, dist[i]);
        }
        return maximum;
        
    }
    void dijkstra(){
        memset(dist, 0x3f, sizeof dist);
        dist[k] = 0;
        
        for(int i = 0 ; i < n; i++){
            int t = -1;
            for(int j = 1; j <= n; j++){
                if(!visited[j] && (t == -1 || dist[t] > dist[j])){
                    t = j;
                }
            }
            cout << t << " ";
            visited[t] = true;
            
            for(int j = 1; j <= n; j++){
                dist[j] = min(dist[j], dist[t]+g[t][j]);
            }
        }
        
    }
};

//堆优化dijkstra
class Solution {
private:
    static const int N = 110, M = 1e5+10;
    int h[N], e[M], ne[M], idx, w[M];
    typedef pair<int, int>PII;
    int dist[N];
    bool visited[N];
    int n, m, k;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        memset(h, -1, sizeof h);
        for(int i = 0; i < times.size(); i++){
            add(times[i][0], times[i][1], times[i][2]);
        }
        n = N, m = times.size(), k = K;
        dijkstra();
        int maximum = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 0x3f3f3f3f) return -1;
            maximum = max(maximum, dist[i]);
        }
        return maximum;
    }
    void add(int a, int b, int c){
        e[idx] = b;
        w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    void dijkstra(){
        memset(dist, 0x3f, sizeof dist);
        dist[k] = 0;
        priority_queue<PII, vector<PII>, greater<PII>>q;
        q.push({0, k});
        while(!q.empty()){
            auto t = q.top();
            q.pop();
            int distance = t.first, point = t.second;
            if(visited[point]) continue;
            for(int i = h[point]; i != -1; i = ne[i]){
                int j = e[i];
                if(dist[j] > distance + w[i]){
                    dist[j] = distance + w[i];
                    q.push({dist[j], j});
                }
            }
        }
    }
};


