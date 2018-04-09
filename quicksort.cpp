#include <iostream>
using namespace std;

/**
  * Hoare partition. It is the first method that was introduced by Hoare.
  * It is also the first method that was used in the quicksort algorithm.
  * @arr store the unsorted elements
  * @start the start position
  * @end the end position
  * @author Junpeng Zhu
*/
int partitionHoare(int arr[], int start, int end){
    int cursorLeft = start - 1; //set cursor for the left value
    int cursorRight = end + 1;   //set cursor for the right value
    int key = arr[start];   // set key value as standard
    while(true){
        do{
            cursorLeft++;
        }while(arr[cursorLeft]<key);
        do{
            cursorRight--;
        }while(arr[cursorRight]>key);
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
  * quicksort algorithm. It is the first introduced by Hoare.
  * @arr store the unsorted elements
  * @start the start position
  * @end the end position
  * @author Junpeng Zhu
*/
void quicksort(int arr[],int start, int end){
    if(start < end){
        int position = partitionHoare(arr,start,end);
        quicksort(arr,start,position-1);
        quicksort(arr,position+1,end);
    }
}

int main(int args, char* argv[])
{
    //int arr[] = {3,2,1};  //success
    //int arr[] = {2,8,7,1,3,5,6,4};   //error
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {2,5,2,4,1,1};   //success
    int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};   //error
    quicksort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i] << " ";
    }
    return 0;
}


