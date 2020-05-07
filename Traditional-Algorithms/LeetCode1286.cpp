class CombinationIterator {
private:
    string s;  //一个解
    vector<string> ans;  //全部解
    stack<string>st;
    int count;
    int nextElement = 0;
public:
    CombinationIterator(string characters, int combinationLength) {
        if(characters.size() == 0){
            ans = vector<string>();
        }else{
            sort(characters.begin(), characters.end());
            count = combinationLength;
            dfs(characters, 0);
        }
    }
    
    string next() {
        string s;
        if(nextElement < ans.size()){
            s = ans[nextElement];
            nextElement++;
        }
        return s;
    }
    
    bool hasNext() {
        if(nextElement < ans.size())
            return true;
        return false;
    }
    void dfs(string characters, int start){
        if(s.size() == count){
            ans.push_back(s);
            return;
        }
        for(int i = start; i < characters.size(); ++i){
            st.push(s);
            s += characters[i];
            dfs(characters, i+1);
            s= st.top();
            st.pop();
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */