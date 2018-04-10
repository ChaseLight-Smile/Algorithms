#include <iostream>
#include <stdio.h>
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
        }while(arr[cursorLeft] < key);
        do{
            cursorRight--;
        }while(arr[cursorRight] > key);
        if(cursorLeft >= cursorRight){
            return cursorRight;
        }
         //swap the values
        int temp = arr[cursorLeft];
        arr[cursorLeft] = arr[cursorRight];
        arr[cursorRight] = temp;
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
    int key = arr[start];   // set key value as standard
    int cursorLeft = start-1; //set cursor for the left value
    int cursorRight = end+1;   //set cursor for the right value
    while(true){

        while(true){
            cursorLeft = cursorLeft+1;
            if(arr[cursorLeft] >= key){
                break;
            }

        }
        while(true){
            cursorRight = cursorRight-1;
            if(arr[cursorRight]<= key){
                break;
            }
        }

        if(cursorLeft < cursorRight){
            //swap the values
            int temp = arr[cursorLeft];
            arr[cursorLeft] = arr[cursorRight];
            arr[cursorRight] = temp;
            //cout << "swap:" << arr[cursorLeft] << " " << arr[cursorRight] << endl;
        }else{
            printf("cursorLeft value is: %i\n",cursorRight);
            return cursorRight;
//            return cursorLeft;
        }
    }
}

/**
  * It is introduced by Lomuto, which enhancing the Hoare partition method.
  * The experimental results show that it is all the correct for any test example.
  * The idea is great.
  * @arr store the unsorted elements
  * @start the start position
  * @end the end position
  * @author Junpeng Zhu
*/
int partitionLomuto(int arr[],int start, int end){
    int key = arr[end];    //set the pivot element
    int cursorLeft = start-1;   //set left cursor
    for (int j = start; j<= end-1;j++){
        if(arr[j] <= key){   // The cursorLeft keep the condition: arr[cursorLeft] <= key,increase
        //if(arr[j] >= key){   // The cursorLeft keep the condition: arr[cursorLeft] >= key, decrease
            cursorLeft++;
            int temp = arr[j];
            arr[j] = arr[cursorLeft];
            arr[cursorLeft]=temp;
        }
    }
    int temp = arr[cursorLeft+1];
    arr[cursorLeft+1] = arr[end];
    arr[end] = temp;
    printf("cursorLeft value is: %i\n",cursorLeft+1);
    return cursorLeft+1;
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
        //int position = partitionHoare(arr,start,end);
        //int position = partitionHoareModify(arr,start,end);  //use partitionHoare is error because of do...while
        int position = partitionLomuto(arr,start,end);
        quicksort(arr,start,position-1);
        quicksort(arr,position+1,end);
        //quicksort(arr,start,position);  //Hoare partition and Hoare modify position
        //quicksort(arr,position+1,end);
    }
}

int main(int args, char* argv[])
{
    //int arr[] = {3,2,1};  //success
    //int arr[] = {2,8,7,1,3,5,6,4};   //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {2,5,2,4,1,1};   //success
    //int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};   //success
    int arr[] = {8,10,7,16,10,3,9,7,20,2}; //success
    //int arr[] = {8,10,7,16,8,3,9,7,20,2}; //success, compare to the above example {8,10,7,16,10,3,9,7,20,2}
    //cout << "arr size:" << sizeof(arr)/sizeof(arr[0]) << endl;
    //int arr[] = {1,1,3};  //success
    //int arr[] = {1,1,1,1,1,1,1};
    quicksort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i] << " ";
    }
    return 0;
}

