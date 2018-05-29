#include <iostream>
using namespace std;

/**
  * It is used to get the maximum and minmum by using the common method.
  * @arr store the array value
  * @length store the array length
  * @author Junpeng Zhu
*/
int* commonMethod(int* arr, int length){
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < length; i++){
        if(max < arr[i]){
            max = arr[i];
        }
        if(min > arr[i]){
            min = arr[i];
        }
    }
    int* results = new int[2];
    results[0]= min;
    results[1] = max;
    return results;
}

/**
  * It is used to get the maximum and minmum by using the enhancing method.
  * The number of comparsion decreases by comparing to the common method.
  * @arr store the array value
  * @length store the array length
  * @author Junpeng Zhu
*/
int* enhancingMethod(int arr[], int length){
    if(length % 2 == 0){
        int max = arr[0]>arr[1]?arr[0]:arr[1];
        int min = arr[0]<arr[1]?arr[0]:arr[1];
        for (int i = 2; i<length;){
            if(arr[i] > arr[i+1]){
                if(arr[i] > max){
                    max = arr[i];
                }
                if(arr[i+1] < min){
                    min = arr[i+1];
                }
                i += 2;
            }else{
                if(arr[i+1] > max){
                    max = arr[i+1];
                }
                if(arr[i]<min){
                    min = arr[i];
                }
                i += 2;
            }
        }
        int* results = new int[2];
        results[0] = min;
        results[1] = max;
        return results;
    }else{
        int max = arr[0];
        int min = arr[0];
        for (int i = 1; i < length ;){
            if(arr[i] > arr[i+1]){
                if(arr[i] > max){
                    max = arr[i];
                }
                if(arr[i+1] < min){
                    min = arr[i+1];
                }
                i += 2;
            }else{
                if(arr[i+1] > max){
                    max = arr[i+1];
                }
                if(arr[i]<min){
                    min = arr[i];
                }
                i += 2;
            }
        }
        int* results = new int[2];
        results[0] = min;
        results[1] = max;
        return results;
    }
}

int main()
{
    //int arr[] = {3,2,1};  //success
    //int arr[] = {2,8,7,1,3,5,6,4};   //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {2,5,2,4,1,1};   //success
    int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};   //success
    //int arr[] = {8,10,7,16,10,3,9,7,20,2}; //success
    //int arr[] = {8,10,7,16,8,3,9,7,20,2}; //success, compare to the above example {8,10,7,16,10,3,9,7,20,2}
    //int arr[] = {1,1,3};  //success
    //int arr[] = {1,1,1,1,1,1,1};   //success
    int length = sizeof(arr)/sizeof(arr[0]);
    //int* results = commonMethod(arr,length);
    int* results = enhancingMethod(arr,length);
    int resultsLength  = sizeof(results)/sizeof(results[0]);
    //cout << sizeof(results)/sizeof(results[0]) << endl;
    for(int i = 0; i < resultsLength;i++){
        cout << results[i] << " ";
    }
    return 0;
}

