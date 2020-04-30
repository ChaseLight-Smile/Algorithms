#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x1;
    double y1;
    double x2;
    double y2;
    double distance;
    double errorX;
    double errorY;
    while (cin >> x1){
        cin >> y1;
        cin >> x2;
        cin >> y2;

        errorX = pow(x2-x1,2);
        errorY = pow(y2-y1,2);

        distance = sqrt(errorX+errorY);
        printf("%.2f\n",distance);
    }
   return 0;
}
