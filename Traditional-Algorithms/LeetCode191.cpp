class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            n -= lowbit(n);
            res++;
        }
        return res;
    }
    long lowbit(long x){
        return x & -x;
    }
};