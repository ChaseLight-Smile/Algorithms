#include <string>
#include <iostream>
using namespace std;

int get_val(char c)
{
	switch (c)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
	return 0;
}

int romanToInt(string s) {
	int size = s.size();
	int result = 0;
	for (int i = 0; i < (size - 1); i++){
		int previous = get_val(s[i]);
		int successor = get_val(s[i+1]);
		if (previous >= successor){
			result += previous;
		}
		else{
			result -= previous;
		}

	}
	result += get_val(s[size - 1]);
	return result;
}

int main(){
	string s = "MCMXCIV";
	int result = romanToInt(s);
	cout << result << endl;
	getchar();
	return 0;
}


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(i + 1 < s.size() && m[s[i]] < m[s[i+1]]) ans -= m[s[i]];
            else ans += m[s[i]];
        }
        return ans;
    }
};
