/**
  * Leetcode 9. Palindrome Number
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }else if (x == 0){
            return true;
        }else{
            int *p = new int[10];
            int size = 0;
            while (x != 0 && size <= 9){
                p[size] = x % 10;
                x /= 10;
                size++;
            }
            size--;
            for (int i = 0; i <= size/2; i++){
                if (p[i] != p[size-i]){
                    delete[] p;
                    return false;
                }else{
                    continue;
                }
            }
            delete[] p;
         return true;
        }
        }
};