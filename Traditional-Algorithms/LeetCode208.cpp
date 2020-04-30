class TrieNode{
public:
    char c;
    unordered_map<char,TrieNode*> children;
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


class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = root;
        int len = word.size();
        for(int i = 0; i < len; i++){
            char wc = word[i];
            if(current->children.find(wc) == current->children.end()){
                TrieNode* newNode = new TrieNode(wc);
                if(i == len-1){
                    newNode->hasWord = true;
                }
                current->children[wc] = newNode;   
            }
            if(i == len-1){
                current->children[wc]->hasWord = true;
            }
            current = current->children[wc];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * current = root;
        int len = word.size();
        for(int i = 0; i < len;i++){
            char wc = word[i];
            if(current->children.find(wc) == current->children.end()){
                return false;
            }
            if(i == len-1){
                return current->children[wc]->hasWord;
            }
            current = current->children[wc];
        }      
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * current = root;
        int len = prefix.size();
        for(int i = 0; i < len;i++){
            char wc = prefix[i];
            if(current->children.find(wc) == current->children.end()){
                return false;
            }
            current = current->children[wc];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */