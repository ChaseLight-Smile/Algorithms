// 试除法寻找约数
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> get_factor(int n){
    vector<int>res;
    for(int i = 1; i <= n / i; i++){
        if(n % i == 0) {
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        auto res = get_factor(x);
        for(auto t: res){
            printf("%d ", t);
        }
        puts("");
    }
    return 0;
}