#include <iostream>
using namespace std;

int* findMaxAndMinValues(int arr[], int start, int end){
    int* results= new int[2];
    if (end == start+1){
        if (arr[start] >= arr[end]){
            results[0] = arr[start];
            results[1] = arr[end];
            return results;
        }else{
            results[0] = arr[end];
            results[1] = arr[start];
            return results;
        }
    }

    if (end == start){
        results[0] = arr[start];
        results[1] = arr[end];
        return results;
    }

    int middle = (start+end)/2;
    int* lResults = findMaxAndMinValues(arr,start,middle);
    int* rResults = findMaxAndMinValues(arr,middle+1,end);

    //merge the results
    if (lResults[0] >= rResults[0]){
        results[0] = lResults[0];
    }else{
        results[0] = rResults[0];
    }

    if (lResults[1] <= rResults[1]){
        results[1] = lResults[1];
    }else{
        results[1] = rResults[1];
    }
    return results;
}



int main()

{

    //int arr[] = {3,2,1};  //success
    //int arr[] = {2,8,7,1,3,5,6,4};   //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {3,5,4,6,2,1};  //success
    //int arr[] = {2,5,2,4,1,1};   //success
    //int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};   //success
    //int arr[] = {8,10,7,16,10,3,9,7,20,2}; //success
    //int arr[] = {8,10,7,16,8,3,9,7,20,2}; //success, compare to the above example {8,10,7,16,10,3,9,7,20,2}
    //int arr[] = {1,1,3};  //success
    int arr[] = {1,1,1,1,1,1,1};   //success
    int length = sizeof(arr)/sizeof(arr[0]);
    int* results = findMaxAndMinValues(arr,0,length-1);
    cout << "Max:" << results[0] << endl;
    cout << "Min:" << results[1] << endl;
    return 0;

}
