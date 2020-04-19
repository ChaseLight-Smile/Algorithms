class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        char ans;
        int i;
        for( i = 0; i < len; i++){
            if(letters[i] > target && target != 'z'){
                ans = letters[i];
                break;
            }
        }
        if(i == len){
            ans = letters[0];
        }
        return ans;
    }
};

//二分检索，和标准的模板相差很大
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        int left = 0;
        int right = len;
        while(left < right){
            int mid = left + (right-left)/2;
            if(letters[mid] < target){
                //说明这个地方一定不是插入target的点，那么此时区间收缩为[mid+1,right]
                //因为我们假设在mid之前进行插入，那么letters[mid] < target ，那么这个点一定不是插入点
                left = mid+1;
                //mid+1之后，可能会超过数组本身的长度，因为right=len，如果一旦超过，就立即返回letters[0]
                if(left >= len){
                    return letters[0];
                }
            }else if(letters[mid] == target){
                //当mid==target,但是可能存在[e,e,e,e,n,n,n,n,n]中插入o,那么我们应该把相等的所有位置都排除掉才能准确的插入
                while(mid+1 < len && letters[mid] == letters[mid+1]){
                    mid++;
                }
                if(mid+1<len){
                     return letters[mid+1];
                }else{
                    return letters[0];
                }  
            }else{
                //这时和letters[mid] < target情况相反
                right = mid;
            }
        }
        return letters[left];
    }
};