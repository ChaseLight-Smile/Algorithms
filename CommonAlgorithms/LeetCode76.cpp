class Solution {
public:
    
    bool validate(int source[], int target[]){
        for(int i = 0 ; i < 256; i++){
            if(target[i] > source[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int sourcemap[256] = {0};
        int targetmap[256] = {0};
        int sourcesize = s.size();
        string str = "";
        int ans = sourcesize + 1;
        int i = 0 , j = 0 ;
        
        int targetsize = t.size();
        for(int i = 0 ; i <targetsize; i++){
            targetmap[t[i]]++;
        }
 
        for(i = 0;i < sourcesize; i++){
            while(j < sourcesize && !validate(sourcemap, targetmap)){
                sourcemap[s[j]]++;
                j++;
            }
            if(validate(sourcemap, targetmap) && ans > (j-i)){
                ans = min(ans, j-i);
                str = s.substr(i,j-i);                      
            }
            sourcemap[s[i]]--;
        }
        return str;
    }
};