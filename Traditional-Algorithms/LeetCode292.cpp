// n过大超出范围
class Solution {
    const static int N = 1e6+10;
    int f[N];
    int s[3] = {1,2,3};
    int n;
public:
    int sg(int x){
        if(f[x] != -1) return f[x];
        unordered_set<int>S;
        for(int i = 0; i < 3; i++){
            int sum = s[i];
            if(x>=sum) S.insert(sg(x-sum));
        }
        for(int i = 0; ;i++){
            if(!S.count(i)){
                return f[x] = i;
            }
        }
    }
    bool canWinNim(int _n) {
        //每个可以取1,2,3块石子，给定一堆石子，总数为n，本质上它为集合-nim游戏，判断先手是否必胜，使用SG函数解，这个题目不简单啊，哈哈
        int res = 0;
        memset(f, -1, sizeof f);
        n = _n;
        res ^= sg(n);
        if(res) return true;
        return false;
    }
};


//正确找规律问题
class Solution {
public:
    bool canWinNim(int _n) {
        return n % 4;
    }
};