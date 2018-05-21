include <iostream>
using namespace std;


int gcd1(int numberA, int numberB){
    int greaterNumber = (numberA>=numberB)?numberA:numberB;
    int smallNumber = (numberA<numberB)?numberA:numberB;

    int gcd = 1;
    int count = 0 ;
    for (int i = 2; i <= smallNumber; i++){
        if (greaterNumber % i == 0  && smallNumber % i ==0){
            gcd = i ;
            count++;
        }else{
            count++;
            continue;
        }
    }
    cout << "The number of gcd1 comparision is count:" << count << endl;
    return gcd;

}

int gcd2(int numberA, int numberB){
    int greaterNumber = (numberA>=numberB)?numberA:numberB;
    int smallNumber = (numberA<numberB)?numberA:numberB;
    if (greaterNumber % smallNumber == 0){
        int gcd = smallNumber;
        int count = 0;
        count++;
        cout << "The number of gcd2 comparision is count:" << count << endl;
        return gcd;
    }else{
        int gcd = 1;
        int count = 0;
        for (int i = 2; i <= smallNumber/2; i++){
            if (greaterNumber % i == 0  && smallNumber % i ==0){
                gcd = i ;
                count++;
            }else{
                count++;
                continue;
            }
        }
        cout << "The number of gcd2 comparision is count:" << count << endl;
        return gcd;
    }
}


int main()
{
    int i = 169;
    int j = 14;
    int gcdA = gcd1(i,j);
    cout <<"gcd1:"<< gcdA << endl;
    int gcdB = gcd2(i,j);
    cout << "gcd2:"<< gcdB << endl;
    return 0;
}

