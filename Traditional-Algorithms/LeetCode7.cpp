class Solution {
public:
    int reverse(int x) {
        long long sum = 0;
        long y = abs(x);
        cout << y << " ";
        while(y){
            sum = sum * 10 + y % 10;
            y /= 10;
        }
        if(sum >= INT_MAX) return 0;
        else if(x < 0){
            return -1* sum;
        }else return sum;
    }
};