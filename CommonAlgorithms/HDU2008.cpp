#include <iostream>
using namespace std;

int main(){
    double a;
    double num;
    while (cin>>a){
        if (a == 0) continue;
        int numN = 0;
        int numP = 0;
        int numZ = 0;
        for (int i = 0; i < a; i++){
            cin >> num;
            if (num >0){
                numP++;
            }
            if (num<0){
                numN++;
            }

            if (num == 0){
                numZ++;
            }
        }
        cout << numN << " " << numZ << " " << numP << endl;
    }
}
