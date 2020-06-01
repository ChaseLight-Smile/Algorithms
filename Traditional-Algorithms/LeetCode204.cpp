class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }
    
    bool isPrime(int n){
        if (n <= 1) return false;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) return false;
            }
        return true;
    }
};


//推荐写法，上面写法在i 很大时，可能会溢出
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }
    
    bool isPrime(int n){
        if (n <= 1) return false;
            for (int i = 2; i <= n/i; i++) {  //这里i <= n/i 不会有溢出问题
                if (n % i == 0) return false;
            }
        return true;
    }
};