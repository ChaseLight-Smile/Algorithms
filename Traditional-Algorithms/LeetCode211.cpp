class TrieNode{
public:
    char c;
    unordered_map<char, TrieNode*> children;
    bool hasWord;
public:
    TrieNode(){
        hasWord = false;
    }
    TrieNode(char ch){
        c = ch;
        hasWord = false;
    }
};


class WordDictionary {
public:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* current = root;
        int len = word.size();
        for(int i = 0; i < len; i++){
            if(current->children.find(word[i]) == current->children.end()){
                TrieNode* newNode = new TrieNode(word[i]);
                if(i == len -1){
                    newNode->hasWord = true;
                }
                current->children[word[i]] = newNode;
            }
            if(i == len-1){
                current->children[word[i]]->hasWord = true;
            }
            current = current->children[word[i]];
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word, 0 , root);
    }
    bool find(string word, int pos, TrieNode* current){
        if(pos == word.size()){
            return current->hasWord;
        }
        
        if(word[pos] == '.'){
            for(auto & n : current->children){
                if(find(word, pos+1, n.second))
                    return true;
            }
            return false;
        }else if(current->children.find(word[pos]) != current->children.end()){
            return find(word, pos+1, current->children[word[pos]]);
        }else{
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */