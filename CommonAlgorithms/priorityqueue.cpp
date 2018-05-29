#include <iostream>
#define ILLEGALPOSITION -1000000
#define MINIMUM -100000000
using namespace std;

/**
  * Keeping the properties of max heap. It is most important proceduce for the heap sort.
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
  * It gets the position of father element for the child i. The index from 0 upto length-1
  * @arr store the value of the heap
  * @length store the array length
  * @i store the child position
  * @position return father position
  * @author Junpeng Zhu
*/
int getFatherPosition(int arr[], int length, int i){
    int position = ILLEGALPOSITION;
    if (i >= length){
        return ILLEGALPOSITION;    //get the illegal position
    }else{
        position = (i-1)/2;
    }
    return position;
}

/**
  * It gets the maximum value for the priority queue.
  * @arr store the value of the heap
  * @length store the length of array
  * @return return arr[0]. It is the maximum for the heap.
  * @author Junpeng Zhu
*/
int heapMaximum(int arr[], int length){
    buildMaxHeap(arr,length);
    return arr[0];
}

/**
  * Delete and return the maximum element.
  * @arr store the value of array
  * @length store the array length
  * @return return the maximum of the priority queue.
  * @author Junpeng Zhu
*/
int deleteMaximum(int arr[], int length){
    buildMaxHeap(arr,length);
    int max = arr[0];
    /**
      * swap the arr[0] and arr[length-1]
    */
    int temp = arr[0];
    arr[0] = arr[length-1];
    arr[length-1] = temp;

    length = length -1 ;
    maxHeapProperties(arr,0,length);
    for (int i = 0 ; i < length; i++){
        cout << arr[i] << " ";
    }
    return max;
}

/**
  * Modify the value for i position, which resluts in increasing the priority.
  * @arr store the value of the priority
  * @length store the array length
  * @i modify the position
  * @key modify the value
  * @author Junpeng Zhu
*/
void modifyPriority(int arr[], int length, int i, int key){
    buildMaxHeap(arr,length);  //build the priority queue
//    for(int j = 0 ;j < length;j++){
//        cout << arr[j] << " ";
//    }
    cout << endl;
    if (i >= length){
        return;  // overflow
    }
    if (i < 0){
        return;   //underflow
    }
    if (i == 0){
        arr[i] = key;
        return;
    }

    if (arr[i] >= key){
        return;   //It is illegal, because the key > arr[i]
    }else{
        arr[i] = key;
//        for(int j = 0 ;j < length;j++){
//            cout << arr[j] << " ";
//        }
     int fatherPosition = ILLEGALPOSITION;
        while(i > 0){
            fatherPosition = getFatherPosition(arr,length,i);
//            cout << fatherPosition << endl;
            if (arr[fatherPosition] < arr[i]){   //swap the valuue, which makes the max heap properties
                int temp = arr[fatherPosition];
                arr[fatherPosition] = arr[i];
                arr[i] = temp;
            }
            i = fatherPosition;
        }
    }
}

/**
  * Modify the value for i position, which resluts in increasing the priority.
  * @arr store the value of the priority
  * @length store the array length
  * @key modify the value
  * @author Junpeng Zhu
*/
void insertPriority(int arr[], int length, int key){
    buildMaxHeap(arr,length);
    arr[length] = MINIMUM;
    length = length+1;
    modifyPriority(arr,length,length-1,key);
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
    //buildMaxHeap(arr,length);
    //int max = heapMaximum(arr,length);
    //int max = deleteMaximum(arr,length);
    //modifyPriority(arr,length,2,1000);
    insertPriority(arr,length,58);
    //cout << "The maximum value is " << max << " for the priority queue."<<endl;
    //maxHeapSort(arr,length);
    for(int i = 0 ;i <= length;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
