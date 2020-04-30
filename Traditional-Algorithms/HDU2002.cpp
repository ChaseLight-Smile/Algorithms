#include <iostream>
#include <cmath>
#define PI 3.1415927
using namespace std;
void volumn(){
    double r;
    while(cin>>r){
        printf("%.3f\n",double(4)/double(3)*PI*pow(r,3));
    }
}

int main(){
    volumn();
    return 0;
}
