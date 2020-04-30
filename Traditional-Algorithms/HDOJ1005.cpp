#include <iostream>
using namespace std;

/**
  * HDOJ1005 recursive solution. Memory Limit Exceeded.
  * @author Junpeng Zhu
*/
int recursiveSum(int a , int b ,int n){
    if (n==1 || n==2){
        return 1;
    }else{
        return (a*recursiveSum(a,b,n-1)+b*recursiveSum(a,b,n-2))%7;
    }
}

int main()
{
    int a=-1, b=-1, n=-1;
    while(true){
        cin >> a;
        cin >> b;
        cin >> n;
        if (a ==0 && b==0 && n==0){
            break;
        }else{
            int result = recursiveSum(a,b,n);
            cout << result << endl;
        }

    }
    return 0;
}

