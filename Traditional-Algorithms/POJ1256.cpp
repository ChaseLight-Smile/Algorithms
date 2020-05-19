#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 20;
int n;
string one;   //一个解
bool visited[N];
string s;

bool isLower(char c){
    if(c >= 'a' && c <= 'z'){
        return true;
    }
    return false;
}
bool isUpper(char c){
    if(c >= 'A' && c <= 'Z'){
        return true;
    }
    return false;
}
struct cmp{
    bool operator()(char& a, char& b){
        if(isLower(a) && isLower(b)){
            return a < b;
        }
        if(isUpper(a) && isUpper(b)){
            return a < b;
        }
        // 'A'<'a' 'a'<'B'
        if(isLower(a) && isUpper(b)){
            if(a == (b + 32)) return a < b;
            else return a < (b+32);
        }
        if(isUpper(a) && isLower(b)){
            if((a+32) == b) return a < b;
            else return (a + 32) < b;
        }
    }
};

void dfs(int u){
    if (u == n){
        for(int i = 0 ; i < n; i++){
            printf("%c", one[i]);
        }
        puts("");
    }
    for(int i = 0 ; i < n; i++){
        if(i > 0 && s[i] == s[i-1] && !visited[i-1]) continue;   //去除重复，保证相同的字符按照出现的先后顺序访问
        if(!visited[i]){
            visited[i] = true;
            one[u] = s[i];
            dfs(u+1);
            visited[i] = false;
        }
    }
    return;
}
int main(){
    int m;
    cin >>m;
    while(m--){
        cin >> s;
        n = s.size();
        sort(s.begin(), s.end(), cmp());
        dfs(0);
    }
    
    return 0;
}