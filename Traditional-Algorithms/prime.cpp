//O(sqrt(n))
#include <iostream>
using namespace std;
int n, m;
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= n / i; i ++){
        if(n % i == 0) return false;
    }
    return true;
}


int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        if(isPrime(m)){
            printf("Yes\n");
        }else printf("No\n");
    }
}


//时间复杂度为O(nlogn)
#include <iostream>
using namespace std;

const int N = 1e6+10;
bool st[N];
int prime[N], cnt;

void isPrime(int x){
    for(int i = 2; i <= x; i++){   //求出1-n中的质数，n可能为质数，所以要<=x
        if(!st[i]) prime[cnt++] = i;
        for(int j = i + i; j <= x; j += i) st[j] = true;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    isPrime(n);
    printf("%d\n", cnt);
}


//改进筛质数方法，O(nloglogn) 粗浅可以认为是O(n)，每个合数用他的某个质因子(但不一定是最小质因子)筛掉即可
#include <iostream>
using namespace std;

const int N = 1e6+10;
int prime[N], cnt;
bool visited[N];
int n;

int factor(int n){
    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            prime[cnt++] = i;
            for(int j = i + i; j <= n; j += i){
                visited[j] = true;
            }
        }   
    }
	for(int i = 0; i < cnt; i++){
		scanf("%d ", prime[i]);  //输出的是1-n之间的所有素数
	}
}

int main(){
    scanf("%d", &n);
    factor(n);
    printf("%d\n", cnt);
    return 0;
}

//线性筛选法，时间复杂度为O(n)，需要理解其证明过程。求出某个数的质因数的个数，并且在prime数组中给出了所有的这些质因数
/**
	线性筛选法的正确性证明：每个合数只会被其最小质因子筛掉，这是线性筛选的特性
*/
#include <iostream>
using namespace std;
const int N = 1e6+10;
bool st[N];
int prime[N], cnt;

void factor(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) prime[cnt++] = i;
        for(int j = 0 ; prime[j] <= n/i; j++){  //枚举所有的质数
            st[prime[j]*i] = true;
            if(i % prime[j] == 0) break;    //说明prime[j]一定是i的最小质因子，因此循环退出
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    factor(n);
    printf("%d\n", cnt);
    return 0;
}

