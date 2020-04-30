class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while(left < right){
            long mid = left +(right-left+1)/2;
            if(mid * mid > num){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(left * left == num){
            return true;
        }
        return false;
    }
};