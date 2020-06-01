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


//筛法求质数个数，算法思想参考 https://zh.wikipedia.org/zh-hans/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
class Solution {
    static const int N = 1e7+10;
    int prime[N], cnt;
    bool visited[N];
public:
    int countPrimes(int n) {
        for(int i = 2; i < n; i++){
            if(!visited[i]){
                prime[cnt++] = i;
                for(int j = i + i; j < n; j += i){
                    visited[j] = true;
                }
            }
        }
        return cnt;
    }
};