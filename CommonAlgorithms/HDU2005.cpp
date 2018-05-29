#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void HDU2005(){
    string s;
    int month[] ={31,0,31,30,31,30,31,31,30,31,30,31};
    while(cin>>s){
        int sum = 0;
        stringstream ss(s);
        string token;
        getline(ss,token,'/');   //get the year
        int year = stoi(token);
        if ((year % 400 == 0) || ((year%100) != 0 && (year % 4 == 0))){
            month[1] = 29;
        }else{
            month[1] = 28;
        }
        getline(ss,token,'/');   //get the month
        int length = stoi(token)-2;
        for (int i = 0 ; i <= length; i++){
            sum += month[i];
        }
        getline(ss,token,'/');   //get the days
        sum += stoi(token);
        cout << sum << endl;
    }
}

int main (){
    HDU2005();
}
