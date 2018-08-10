#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

bool primeImpoving(int);
bool fermatsTheorem(int);

int main (){
	int x = 1398;
	bool flag1 = primeImpoving(x);
	bool flag2 = fermatsTheorem(x);
	cout << flag1 << endl;
	cout << flag2 << endl;    // test is probability correcting;
	return 0;
}



bool primeImpoving(int x){
	int immidiateValue = (int)sqrt(x);
	for (int i = 2; i <= immidiateValue; i++){
		if (x % i == 0){
			cout << "x is not prime number" << endl;
			return false;
		}
	}
	cout << "x is prime number" << endl;
 	return true;
}

/**
 * The Fermats's Little Theorem is a approximate way for testing prime.
 * The random number: https://www.cnblogs.com/afarmer/archive/2011/05/01/2033715.html
 */
bool fermatsTheorem(int x){
	srand((unsigned)time(0));
	int random = rand() % (x-1) + 1;
	cout << "random number is:" << random << endl;
	int temp = (int)pow(double(random),double(x));
	if( temp % x == x ){
		cout << "x is prime number" << endl;
		return true;
	}else{
		cout << "x is not prime number" << endl;
		return false;
	}
}
