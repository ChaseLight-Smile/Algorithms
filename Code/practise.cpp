#include <iostream>
#include <array>
#include <cmath>
#include <stack>
using namespace std;

/**
  * Reversing the int type number.
  * It is complex, and the input parameter n is required.
  * @num the int type number
  * @n the number of bit for the number
  * @author Junpeng Zhu
*/
void reverseInt(int num, int n){
    int result = (int)(num/(pow(10,n-1)));
    stack<int> resultStack;
    resultStack.push(result);

    while(n > 1){
        num = (int)((num-result*pow(10,n-1)));   //get new num
        n -= 1;    //get the bits new number
        result = (int)(num/(pow(10,n-1)));
        cout << "put into number:" << result <<endl;
        resultStack.push(result);
    }

    while (!resultStack.empty()){
        int top = resultStack.top();
        resultStack.pop();
        cout << top;
    }

    return;

}

/**
  * It is simple.
  * @num the int type number
  * @author Junpeng Zhu
*/
int commonReverseInt(int num){
    int remainder = 0;
    int reverseNumber = 0;
    while(num != 0){
        remainder = num%10;
        reverseNumber = reverseNumber*10 + remainder;
        num /= 10;
    }
    cout << reverseNumber;
    return reverseNumber;
}
int main()
{
    int num = 45100;
    int n = 5;
//    int num = 4567;
//    int n = 4;
    //reverseInt(num,n);
    commonReverseInt(num);
    return 0;
}

