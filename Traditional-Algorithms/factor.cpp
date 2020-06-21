#include <iostream>
using namespace std;

void factor(int n){
    for(int i = 2;i <= n / i; i++){
        if(n % i == 0){
            //说明i一定是一个质因子，比如360 = 2 * 2 * 2 * 3 * 3 * 5，当i等于4时，不满足n%i == 0 是因为
            // 从2-3之间存在4的质因子，4的所有质因子全部在到达4之前被分解完了，也就是说这个条件中隐含了
            // 当到达i时，2-i-1之间不存在i的质因子，所以i一定为质数
            int count = 0;
            while(n % i == 0){   //统计包含几个等于i的质因子
                n /= i;
                count++;
            }
            printf("%d %d\n", i, count);
        }
    }
    if(n > 1) printf("%d %d\n", n, 1);  //因为在循环中只检查了小于sqrt(n)之前的所有质因子
                                        //推论：如果在n中有一个大于sqrt(n)的质因子，那么有且只有一个
                                        //因此，检查最终的n，可以知道是否存在唯一一个大于sqrt(n)的质因子
}

int main(){
    int n, m;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        factor(m);
        puts("");
    }
    return 0;
}