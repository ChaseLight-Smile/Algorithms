// 整数N的欧拉函数的值定义为1~N中与N互质的数的个数，https://zh.wikipedia.org/wiki/%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0#%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B8%E7%9A%84%E5%80%BC
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int m;
        scanf("%d", &m);
        int res = m;
        for(int i = 2; i <= m/i; i++){
            if(m % i == 0){
                //说明此时i为一个质因子。
                res = res / i * (i-1);  //这里先执行了除以质因子的操作，因为先做乘法可能会溢出
                while(m % i == 0) m /= i;
            }
        }
        if(m > 1) res = res / m * (m-1);
        printf("%d\n", res);
    }
    return 0;
}

// 筛法求1~N中每个数的euler函数值
#include <iostream>
using namespace std;
typedef long long LL; 
const int N = 1e6+10;
bool st[N]; //表示每个数是否被筛掉
int prime[N], cnt;
int e[N];   //存放1~N中每个数的euler函数
int n;

void get_euler(int n){
    e[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            prime[cnt++] = i;
            e[i] = i-1;   
        }
        
        for(int j = 0; prime[j] <= n / i; j++){
            st[prime[j] * i] = true;
            if(i % prime[j] == 0){
                e[prime[j] * i] = prime[j] * e[i];  //欧拉函数求法
                break;  //线性优化
            }
            e[prime[j] * i] = (prime[j]-1)*e[i];  //欧拉函数求法
        }
    }
}

int main(){
    scanf("%d", &n);
    get_euler(n);
    LL res = 0;
    for(int i = 1; i <= n; i++){
        res += e[i];
    }
    printf("%ld\n", res);  //注意这里是ld，结果应该为long long
    return 0;
}