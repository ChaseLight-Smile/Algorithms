#include <iostream>
#include <cstring>
using namespace std;

/**
  * It is used to get the maximum for the array.
  * @arr store the value of the array
  * @length store the array length
  * @author Junpeng Zhu
*/
int maximum(int arr[], int length){
    int max = arr[0];    // set the arr[0], it is the first element for the array, as the maximum value
    for (int i = 1; i < length; i++){
        if(arr[i] > max){
            max = arr[i];
        }else{
            continue;
        }
    }
    return max;
}

/**
  * counging sort.
  * Note: The value of different index for the array is from 0 to k, which k is the maximum.
  * @arr store the value of unsorted array
  * @length store the length of unsorted array
  * @return return sorted array
  * @author Junpeng Zhu
*/
int* countingsort(int arr[], const int length){
    int max = maximum(arr,length);
    int countingLength = max+1;
    int* sortedArray = new int[length]; //store the sorted array. Because the length is variable, sortedArray should be allcated in heap area.
    int countingArray[countingLength];  //Initial the counting array and the value of elements is 0;
//    for (int i = 0 ; i < countingLength; i++){
//        countingArray[i] = 0;
//    }
    memset(countingArray,0,countingLength*sizeof(countingArray[0]));  //set 0 in every unit for the countingArray

    for (int i = 0 ; i < length; i++){
        countingArray[arr[i]] += 1;
    }
    for (int i = 1; i < countingLength; i++){
        countingArray[i] = countingArray[i] + countingArray[i-1];
    }

    //put arr into countingArray
    for (int i = length-1; i >=0; i--){
        sortedArray[countingArray[arr[i]]-1] = arr[i];
        countingArray[arr[i]] -= 1;
    }
//    for(int i = 0 ;i < length;i++){
//        cout << sortedArray[i] << " ";
//    }
    return sortedArray;    // resulting hanging pointer. It is not correct.
}

int main()
{
    //int arr[] = {3,2,1};  //success
    //int arr[] = {2,8,7,1,3,5,6,4};   //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {2,5,2,4,1,1};   //success
    int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};   //success
    //cout << length << endl;
    //int arr[] = {8,10,7,16,10,3,9,7,20,2}; //success
    //int arr[] = {8,10,7,16,8,3,9,7,20,2}; //success, compare to the above example {8,10,7,16,10,3,9,7,20,2}
    //cout << "arr size:" << sizeof(arr)/sizeof(arr[0]) << endl;
    //int arr[] = {1,1,3};  //success
    //int arr[] = {1,1,1,1,1,1,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    //int max  = maximum(arr,length);
    int *sortedResults = countingsort(arr,length);
    for(int i = 0 ;i < length;i++){
        cout << sortedResults[i] << " ";
    }
    return 0;
}

