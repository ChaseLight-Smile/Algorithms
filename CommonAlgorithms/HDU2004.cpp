#include <iostream>
using namespace std;
void HDU2004(){
    int grade;
    while(cin>>grade){
        if(grade >=90 && grade <= 100){
            cout << "A" << endl;
        }else if(grade >= 80 && grade < 90){
            cout << "B" << endl;
        }else if (grade >= 70 && grade < 80){
            cout << "C" << endl;
        }else if (grade >= 60 && grade < 70){
            cout << "D" << endl;
        }else if (grade >= 0 && grade < 60){
            cout << "E" << endl;
        }else{
            cout << "Score is error!" << endl;
        }
    }
}

int main()
{
   HDU2004();
}
