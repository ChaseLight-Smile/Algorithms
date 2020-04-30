class Solution {
public:
    void graphTraversal() {
        vector<vector<int>> nums = {{ 1, 2 }, { 1, 3 }, { 1, 4 }, { 2, 5 }, { 2, 6 }, { 3, 7 }, { 4, 7 }, { 4, 8 }, { 7, 8 }, {5,6} };
        vector<vector<int>> graph(100);
        for(auto &m : nums){
            graph[m[0]].push_back(m[1]);
        }
        
        vector<int> visitedDFS(100);
        vector<int> ansDFS = graphDFS(graph, 1, visitedDFS);
        for(auto & m : ansDFS){
            cout << m << " ";
        }
        cout << endl;
        vector<int> visitedBFS(100);
        vector<int> ansBFS = graphBFS(graph, 1, visitedBFS);
        for(auto & n : ansBFS ){
            cout << n << " ";
        }
        return;
    }
    
    vector<int> graphDFS(vector<vector<int>>& graph, int x, vector<int>& visited){
        visited[x] = 1;
        vector<int> ans;
        ans.push_back(x);
        vector<int> ans_children;
        for(int i = 0; i < graph[x].size(); i++){
            int u = graph[x][i];
            if(visited[u] != 1){
                visited[u] = 1;
                ans_children = graphDFS(graph, u, visited);
                ans.insert(ans.end(), ans_children.begin(), ans_children.end());
            }
        }
        return ans;
    }
    vector<int> graphBFS(vector<vector<int>>& graph, int x, vector<int>& visited){
        queue<int> q;
        q.push(x);
        visited[x] = 1;
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];
                if(visited[v] != 1){
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};