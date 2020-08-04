class Solution {
    static const int N = 2e3+10;
    int len[N], cnt[N];  //len表示当前以i结尾的，cnt表示当前以i结尾的子序列的个数
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            len[i] = cnt[i] = 1;
            for(int j = 0; j < i; j++){
                //枚举起始节点
                if(nums[i] > nums[j]){
                    if(len[i] == len[j]+1){
                        //说明此时以i为结尾的子串的倒数第二个位置为j
                        cnt[i] += cnt[j];
                    }else if(len[i] < len[j]+1){
                        //直接用j来更新i，因为i是j的后置节点，如果发现以i为结尾的子序列的长度小于以j为结尾的子序列长度+1，说明i的值没有及时更新
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }
                }
            }  
            //更新最大子序列的长度
            maxLen = max(maxLen, len[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(len[i] == maxLen) res += cnt[i];
        }
        return res;
    }
};