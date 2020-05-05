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