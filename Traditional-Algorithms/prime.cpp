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

//筛法求质数，O(nlogn)
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
        }
        for(int j = i + i; j <= n; j += i){
            visited[j] = true;
        }
    }
}

int main(){
    scanf("%d", &n);
    factor(n);
    printf("%d\n", cnt);
    return 0;
}

//改进筛质数方法，O(nloglogn) 粗浅可以认为是O(n)
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