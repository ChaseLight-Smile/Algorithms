#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 10;
typedef pair<int, int> PII;
int g[N][N], d[N][N];
PII pr[N][N]; 
queue<PII>q;
int n = 5, m = 5;

vector<PII> bfs(){
    q.push({0,0});  //将起始点放入队列
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >=0 && y < m && g[x][y] == 0 && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;
                pr[x][y] = t;
                q.push({x,y});
            }
        }
    }
    int x = n-1, y  = m-1;
    vector<PII>ans;
    while(x || y){
        ans.push_back({x,y});
        auto t = pr[x][y];
        x = t.first, y = t.second;
    }
    ans.push_back({0,0});
    return ans;
}

int main(){
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> g[i][j];
        }
    }
    vector<PII> ans = bfs();
    for(int i = ans.size()-1; i >= 0; i--){
        printf("(%d, %d)\n", ans[i].first, ans[i].second);
    }
    return 0;
}