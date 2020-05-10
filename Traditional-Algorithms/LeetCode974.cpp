//TLE
class Solution {
private:
    static const int N = 30010;
    int s[N], a[N];
public:
    int subarraysDivByK(vector<int>& A, int K) {
        for(int i = 1; i <= A.size(); i++){
            a[i] = A[i-1];
        }
        for(int i = 1; i <= A.size(); i++){
            s[i] = s[i-1] + a[i];
        }
        int sum = 0;
        for(int i = 1; i <= A.size(); i++){
            for(int j = i; j <= A.size(); j++){
                int tmp = s[j] - s[i-1];
                if(tmp % K == 0){
                    sum++;
                }
            }
        }
        return sum;
    }
};