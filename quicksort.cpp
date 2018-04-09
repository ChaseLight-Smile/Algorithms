#include <iostream>
using namespace std;

/**
  * Hoare partition.It is the first method that was introduced by Hoare.
  * It is also the first method that was used in the quicksort algorithm.
  * @arr store the unsorted elements
  * @start the start position
  * @end the end position
  * @author Junpeng Zhu
  * The implementation is error. the most results are error.
*/
int partitionHoare(int arr[], int start, int end){
    int cursorLeft = start - 1; //set cursor for the left value
    int cursorRight = end + 1;   //set cursor for the right value
    int key = arr[start];   // set key value as standard
    while(true){
        do{   //It should be avoided to use do...while
            cursorLeft++;
        }while(arr[cursorLeft]<=key);
        do{
            cursorRight--;
        }while(arr[cursorRight]>=key);
        if(cursorLeft < cursorRight){
            //swap the values
            int temp = arr[cursorLeft];
            arr[cursorLeft] = arr[cursorRight];
            arr[cursorRight] = temp;
        }else{
            return cursorRight;
        }
    }
}

/**
  * Hoare partition modify. It is the first method that was introduced by Hoare.
  * It is also the first method that was used in the quicksort algorithm.
  * @arr store the unsorted elements
  * @start the start position
  * @end the end position
  * @author Junpeng Zhu
  * It is error when it is equal for the any two elements in the arr. for example:
  * int arr[] = {8,10,7,16,10,3,9,7,20,2}; //error
*/
int partitionHoareModify(int arr[], int start, int end){
    int cursorLeft = start; //set cursor for the left value
    int cursorRight = end;   //set cursor for the right value
    int key = arr[start];   // set key value as standard
    while(true){
        while(arr[cursorLeft] < key){
            cursorLeft++;
        }
        while(arr[cursorRight] > key){
            cursorRight--;
        }
        if(cursorLeft < cursorRight){
            //swap the values
            int temp = arr[cursorLeft];
            arr[cursorLeft] = arr[cursorRight];
            arr[cursorRight] = temp;
            cout << "swap:" << arr[cursorLeft] << " " << arr[cursorRight] << endl;
        }else{
            return cursorRight;
//            return cursorLeft;
        }
    }
}

int partitionLomuto(int arr[],int start, int end){

    return 0;
}
/**
  * quicksort algorithm. It is the first introduced by Hoare.
  * @arr store the unsorted elements
  * @start the start position
  * @end the end position
  * @author Junpeng Zhu
*/
void quicksort(int arr[],int start, int end){
    if(start < end){
        int position = partitionHoareModify(arr,start,end);  //use partitionHoare is error because of do...while
        quicksort(arr,start,position-1);
        quicksort(arr,position+1,end);
    }
}

int main(int args, char* argv[])
{
    //int arr[] = {3,2,1};  //success
    //int arr[] = {2,8,7,1,3,5,6,4};   //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {2,5,2,4,1,1};   //error
    //int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};   //success
    int arr[] = {8,10,7,16,10,3,9,7,20,2}; //error
    quicksort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i] << " ";
    }
    return 0;
}

