/** 计算约数个数
	输入样例：
	3
	2
	6
	8
	输出样例：
	12
*/
#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9+7;
typedef long long LL;
int main(){
    int n;
    scanf("%d", &n);
    unordered_map<int, int>m;   //保存所有的质因数及该质因数对应的个数
    while(n--){
        int x;
        scanf("%d", &x);
        for(int i = 2; i <= x/i; i++){
            while(x % i == 0){
                x /= i;
                m[i]++;
            }
        }
        if(x > 1) m[x]++;
    }
    LL res = 1;
    for(auto t: m){
        res = res * (t.second+1) % mod;
    }
    cout << res<< endl;
    return 0;
}


/** 计算所有约数之和
	输入样例：
	3
	2
	6
	8
	输出样例：
	252
*/

#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9+7;
typedef long long LL;
int main(){
    int n;
    scanf("%d", &n);
    unordered_map<int, int>m;  
    while(n--){
        int x;
        scanf("%d", &x);
        for(int i = 2; i <= x/i; i++){
            while(x % i == 0){
                x /= i;
                m[i]++;
            }
        }
        if(x > 1) m[x]++;   //唯一一个大于sqrt(x)的质因数
    }
    LL res = 1;
    for(auto t: m){
        int p = t.first, a = t.second;
        LL tt = 1;
        while(a--) tt = (p * tt + 1)%mod;
        res = res * tt % mod;
    }
    cout << res<< endl;
    return 0;
}