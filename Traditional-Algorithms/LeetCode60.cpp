class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        int i,j;
        for(i = 1; i <= n; ++i){
            s += to_string(i);
        }
        if(k == 1){
            return s;
        }
        k--;
        while(k>0){
            i = s.size()-1;
            while(i > 0 && s[i-1] >= s[i]){
                --i;
            }
            int j = s.size()-1;
            while(j > i-1 && s[j] <= s[i-1]){
                --j;
            }
            swap(s[i-1], s[j]);
            reverse(s.begin()+i, s.end());
            k--;
        }
        return s;
    }
};