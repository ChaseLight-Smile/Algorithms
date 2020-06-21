class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1){
            return false;
        }
        int res = 0;
        for(int i = 1; i <= num/i; i++){
            if(num % i == 0){
                res += i;
                if(i != num/i && i != num && num/i != num) res += num/i;
            }
        }
        return res == num;
    }
};