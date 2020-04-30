class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        bool whiteFlag = true;
        bool flag = true;
        bool digitFlag = true;
        string ans="";
        for(int i = 0 ; i < len; i++){
            if(str[i] == ' ' && whiteFlag){
                continue;
            }else if((str[i] == '+' || str[i] == '-') && flag ){
                whiteFlag = false;
                ans = ans + str[i];
                flag = false;
            }else if(isalpha(str[i]) != 0){
                digitFlag = false;
                flag = false;
                whiteFlag = false;
            }else if(isdigit(str[i]) != 0 && digitFlag){
                ans = ans+str[i];
                flag = false;
                whiteFlag = false;
            }else if(str[i] == '.'){
                break;
            }else
                break;
        }
        
        double sum = 0;
        for(int i = 0 ; i < ans.size(); i++){
            if(ans[i] == '+' || ans[i] == '-'){
                continue;
            }
            sum = sum*10+(ans[i]-'0');
        }
        //cout << sum;
        if(ans[0] == '+'){
            if(sum >= INT_MAX){
                return INT_MAX;
            }else{
                return (int)sum;
            }
        }
        if(ans[0] == '-'){
            if(sum > INT_MAX){
                return INT_MIN;
            }else{
                return -1*(int)sum;
            }
        }
       if(sum >= INT_MAX){
            return INT_MAX;
        }else{
            return (int)sum;
        }
    }
};