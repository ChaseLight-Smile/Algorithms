#include <stdio.h>
#include <stdlib.h>

float sumArray(float arr[], unsigned length){
    int i = 0;
    float sum = 0.0;
    for (i = 0 ; i < length-1; i++){
        printf("%x\n",length-1);  //ffffffff, This is the complement of -1.
        sum += arr[i];    // The index is overflow.
    }
    return sum;
}

int main()
{
    float arr[] = {1.2,2.3,5.0};
    unsigned length = sizeof(arr)/sizeof(arr[0]);
    //float sum = sumArray(arr,length);
    float sum = sumArray(arr,0);
    printf("%f",sum);
    return 0;
}



