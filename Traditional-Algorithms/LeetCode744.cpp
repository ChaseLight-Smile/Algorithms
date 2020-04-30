class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        char ans;
        int i;
        for( i = 0; i < len; i++){
            if(letters[i] > target && target != 'z'){
                ans = letters[i];
                break;
            }
        }
        if(i == len){
            ans = letters[0];
        }
        return ans;
    }
};

//二分检索
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        if(len == 0){
            return 0;
        }
        int left = 0;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(letters[mid] > target){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(letters[left] > target){
            return letters[left];
        }else if(letters[left] <= target){
            if(left < len-1){
                return letters[left+1];
            }else{
                return letters[0];
            }
        }
        return 0;
    }
};