class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        long mid;
        long start = 1, end = x;
        while(start + 1 < end){
            mid = (start+end)/2;
            if(mid * mid <= x){
                start = mid;
            }else
                end = mid;
        }
        if(end * end < x)
            return end;
        return start;
    }
};


//解法二：采用binary search 排除法
class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        long start = 1, end = x;
        while(start < end){
            long mid = start + (end-start+1)/2;
            if(mid * mid > x){
                end = mid-1;
            }else
                start = mid;
        }
        return start;
    }
};