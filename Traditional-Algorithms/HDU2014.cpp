#include <iostream>
using namespace std;

void HDU2014(){
    int n;
    while (cin >> n){
        int arr[n];
        // int *arr = new int[n]; //correct
        int current;
        for (int i = 0 ; i < n ; i++){   //initial the score
            cin >> current;
            arr[i] = current;
        }

        int max;
        int min;

        if (n %2 == 0){
            if (arr[0] >= arr[1]){
                max = arr[0];
                min = arr[1];
            }else{
                max = arr[1];
                min = arr[0];
            }

            for (int i = 2 ; i <= n-2; i++){
                if (arr[i] >= arr[i+1]){
                    if (arr[i] >= max){
                        max = arr[i];
                    }
                    if (arr[i+1] <= min){
                         min = arr[i+1];
                    }
                }else{
                    if (arr[i+1] >= max){
                        max = arr[i+1];
                    }
                    if (arr[i] <= min){
                        min = arr[i];
                    }
                }
            }
        }else{
            max = arr[0];
            min = arr[0];
            for (int i = 1; i <= n-2; i++){
                 if (arr[i] >= arr[i+1]){
                    if (arr[i] >= max){
                        max = arr[i];
                    }
                    if (arr[i+1] <= min){
                         min = arr[i+1];
                    }
                }else{
                    if (arr[i+1] >= max){
                        max = arr[i+1];
                    }
                    if (arr[i] <= min){
                        min = arr[i];
                    }
                }
            }
        }
        int sum = 0 ;
            int size = n;
            for (int i = 0 ; i < n ; i++){
                if (arr[i] == max || arr[i] == min){
                    size--;
                    continue;
                }else{
                    sum += arr[i];
                }
            }
            double out = 0;
            out = (double)sum/(double)size;
            printf("%.2f\n",out);
    }
}

int main (){
  HDU2014();
  return 0;
}
