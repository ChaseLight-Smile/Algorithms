#include <iostream>
using namespace std;

/**
  * The max sub sequences problem. It is implemented by using on-line method.
  * The complexity of method is O(n), which is linear time. It is the most superior method.
  * @author Junpeng Zhu
  * @arr the parameter of array
  * @length the parameter of array length
*/
int maxSubSeqSum(int arr[], int length){
    int currentSum = 0;
    int maxSum = 0;
    for (int i = 0 ; i < length ; i++){
        currentSum += arr[i];
        if (currentSum > maxSum){
            maxSum = currentSum;
        }else if (currentSum < 0){
            currentSum = 0 ;
        }
    }
    return maxSum;
}


int main()
{
    int arr[] = {-1,3,-2,4,-6,1,6,-1};
    int length = sizeof(arr)/sizeof(arr[0]);
    int max = maxSubSeqSum(arr,length);
    cout << max << endl;
    return 0;
}

