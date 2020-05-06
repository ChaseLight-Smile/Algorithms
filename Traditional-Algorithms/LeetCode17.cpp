//BFS
class Solution {
private:
    string character[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return vector<string>();
        }
        vector<string> combinations(1, "");
        for(auto  n : digits){
            vector<string> current;
            for(auto m : character[n -'2']){
                for(auto s: combinations){
                    s+=m;
                    current.push_back(s);
                }
            }
            combinations = current;
        }
        return combinations;
    }
};

//DFS+backtracking
class Solution {
private:
    string character[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return vector<string>();
        }
        vector<string>ans;
        string s = "";
        dfs(digits, ans, s, 0);
        return ans;
    }
    
    void dfs(string digits, vector<string>& ans, string& s, int start){
        if(start == digits.size()){
            ans.push_back(s);
            return;
        }
        for(int i = 0 ; i < character[digits[start]-'2'].size(); ++i){
            string tmp = s;
            s = s + character[digits[start]-'2'][i];
            dfs(digits, ans, s, start+1);
            s = tmp;
        }
        return;
    }
};