class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int res = 0;
        for(int i = 0; i < piles.size(); i++){
            res ^= piles[i];
        }
        if(res) return true;   //如果异或不为0，则先手必胜，否则先手必败
        return false;
    }
};