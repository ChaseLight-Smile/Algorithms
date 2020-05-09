class Solution {
public:
    string addBinary(string num1, string num2) {
        vector<int>A, B;
        for(int i = num1.size()-1; i >= 0 ; i--){
            A.push_back(num1[i] - '0');
        }
        for(int i = num2.size()-1; i >= 0; i--){
            B.push_back(num2[i] - '0');
        }
        auto C = add(A, B);
        string ans;
        for(int i = C.size()-1; i>= 0; i--){
            ans += to_string(C[i]);
        }
        return ans;
    }
    
    vector<int> add(vector<int>& A, vector<int>& B){
        vector<int> C;
        int t = 0;
        for(int i = 0; i < A.size() || i < B.size(); i++){
            if(i < A.size()) t += A[i];
            if(i < B.size()) t += B[i];
            C.push_back(t%2);
            t /= 2;
        }
        if(t) C.push_back(1);
        return C;
    }
};