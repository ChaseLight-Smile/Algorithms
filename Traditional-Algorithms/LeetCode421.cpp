class Solution {
private:
    vector<int> nums;
    static const int N = 3e6+10;   //数据规模为10^6，这时候一般要求算法的时间复杂度降到O(nlogn)该题目为O(n)
    int son[N][2], idx;
public:
    int findMaximumXOR(vector<int>& _nums) {
        nums = _nums;
        for(int i = 0 ; i < nums.size(); i++){
            insert(nums[i]);
        }
        int res = 0;
        for(int i = 0 ; i < nums.size(); i ++){
            res = max(res, query(nums[i]));
        }
        return res;
    }
    
    void insert(int x){
        int p = 0 ;
        for(int i = 30; i >= 0; i--){
            int u = x >> i & 1; 
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
    }
    int query(int x){
        int p = 0,res = 0;
        for(int i = 30; i >=0; i--){
            int u = x >> i & 1;
            if(son[p][!u]){
                res += 1 << i;
                p = son[p][!u];
            }else p = son[p][u];
        }
        return res;
    }
};


//在cb上调试时的代码
#include <iostream>
using namespace std;

const int N = 1e5+10, M = 3e6+10;

int son[M][2], idx;
int a[N];

void insert(int x){
    int p = 0 ;
    for(int i = 30 ; i >= 0; i--){
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];  //插入数，创建新节点
    }
}

int query(int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(son[p][!u]){
            res += 1 << i;
            p = son[p][!u];
        }else p = son[p][u];
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0 ; i < n; i++){
        res = max(res, query(a[i]));
    }
    printf("%d\n", res);
    return 0;
}