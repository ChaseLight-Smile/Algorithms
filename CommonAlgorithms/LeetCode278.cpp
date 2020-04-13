// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long start = 1;
        long end = n;
        while(start < end){
            long mid = (start + end)/2;
            if(!isBadVersion(mid)){
               start = mid+1; 
            }else{
                end = mid;
            }
        }
        return (int)start;
    }
};