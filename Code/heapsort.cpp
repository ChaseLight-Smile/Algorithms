#include <iostream>
using namespace std;

/**
  * Keep the properties of max heap. It is most important proceduce for the heap sort.
  * Note: Because the array index from 0 to length-1 in my implement, left child position is 2*i + 1
  * and right position is 2*i + 2.
  * @arr store the value of the heap
  * @i adjust the value makes arr keep max heap properties
  * @length store the array length
  * @author Junpeng Zhu
*/
void maxHeapProperties(int arr[],int i,int length){
    int leftPosition = 2*i+1;   //get the left child position of position i, index >=0
    int rightPosition = 2*i+2;   //get the right child position of position i, index >=0
    int largestPosition = 0 ;   //It is a position for in arr[i], arr[leftPosition] and arr[rightPosition]
    if(leftPosition < length && arr[i] < arr[leftPosition]){   //compare arr[i], it is a root , with arr[leftPosition]
        largestPosition = leftPosition;   // Note: leftPosition < length. If not, the array index overflows.
    }else{
        largestPosition = i;
    }

    if(rightPosition < length && arr[largestPosition] < arr[rightPosition]){  //compare arr[largestPosition] with arr[rightPosition]
        largestPosition =  rightPosition;
    }

    if(largestPosition != i){
        int temp = arr[i];// It shoule be swap for arr[i] and arr[largestPosition]
        arr[i] = arr[largestPosition];
        arr[largestPosition] = temp;
        maxHeapProperties(arr,largestPosition,length);  //recursive call the maxHeapProperties, because largest position is modified
    }
}

/**
  * Build max heap.
  * Note: In my implement, the array index from 0 to length-1, which results i from length/2-1 downto 0.
  * @arr store the value of the heap
  * @length store the array length
  * @author Junpeng Zhu
*/

void buildMaxHeap(int arr[], int length){
    for(int i = length/2-1; i>=0; i--){
        maxHeapProperties(arr,i,length);
    }
}

/**
  * Max heap sort.
  * @arr store the value of unsorted
  * @length store the array length
  * @author Junpeng Zhu
*/
void maxHeapSort(int arr[], int length){

}

int main()
{
    //int arr[] = {3,2,1};  //success
    //int arr[] = {2,8,7,1,3,5,6,4};   //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {2,5,2,4,1,1};   //success
    //int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};   //success
    //cout << length << endl;
    int arr[] = {8,10,7,16,10,3,9,7,20,2}; //success
    //int arr[] = {8,10,7,16,8,3,9,7,20,2}; //success, compare to the above example {8,10,7,16,10,3,9,7,20,2}
    //cout << "arr size:" << sizeof(arr)/sizeof(arr[0]) << endl;
    //int arr[] = {1,1,3};  //success
    //int arr[] = {1,1,1,1,1,1,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr,length);
    for(int i = 0 ;i < length;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

