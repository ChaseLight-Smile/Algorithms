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