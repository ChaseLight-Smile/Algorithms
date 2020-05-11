#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 300010;
int a[N], s[N]; //保存前缀和性质
vector<int> all;
typedef pair<int, int> PII;
vector<PII> add;
vector<PII> query;

int find(int x){
    int l = 0, r = all.size()-1;
    while(l<r){
        int mid = l + r >>1;
        if(all[mid] >= x) r = mid;
        else l = mid+1;
    }
    return r+1;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }
    for(int i = 0 ; i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }
    
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    
    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;
    }
    for(auto item : query){
    
    }
    
    //初始化前缀和
    for(int i = 1; i<=all.size(); i++){
        s[i] = s[i-1] + a[i];
    }
    
    //处理询问
    for(auto item : query){
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l-1] << endl;
    }
    
    return 0;
    
}