#include <iostream>
using namespace std;

void HDU2016(){
    int count;
    while(cin >> count){
        if (count == 0){
            break;
        }
        int *arr = new int[count];
        int m = 0 ;
        for (int i = 0; i < count ; i++){
            cin >> m;
            arr[i] = m;
        }
        int min = arr[0];
        int current;
        for (int i = 1; i < count ; i++){
            if (arr[i] < min){
                min = arr[i];
                current = i;
            }
        }

        int temp = arr[current];
        arr[current] = arr[0];
        arr[0] = temp;

        for (int i = 0; i < count-1; i++){
            cout << arr[i] << " ";
        }
        cout << arr[count-1]<< endl;
    }
}

int main(){
    HDU2016();
    return 0;
}
