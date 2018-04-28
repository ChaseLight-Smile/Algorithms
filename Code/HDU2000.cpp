#include <iostream>
#include <string>
using namespace std;
/**
  * sort ASCII alphabet using insertion sort.
  * @author Junpeng Zhu
*/
int main()
{
    string s;
    while (cin >> s){
        char min;
        for(unsigned int i = 1; i < s.length(); i++){
            min = s[i];
            int k = i;
            for (int j = i-1; j >=0; j--){
                if (min < s[j]){
                    s[j+1] = s[j];
                    k = j;
                }
                else{
                    break;
                }
            }
            s[k] = min;
        }
        cout << s[0] << " " << s[1] << " " << s[2] << endl;
    }
    return 0;
}

