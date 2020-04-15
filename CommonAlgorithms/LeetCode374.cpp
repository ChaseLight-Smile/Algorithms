/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1; 
        int right = n;
        while(left < right-5){
            int mid = left + (right-left)/2;
            if(guess(mid) == 0){
                return mid;
            }else if(guess(mid) == -1){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        for(int i = left; i <= right; i++){
            if(guess(i) == 0){
                return i;
            }
        }
        return -1;
    }
};