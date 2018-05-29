/**
  * How to split a string in C++.
  * Java has String.split(), Python has string.split(). There is no simple
  * string-spliting method in C++, but there are plenty of ways of doing it.
*/

vector<string> split1(const string& str)
{
    istringstream iss(str);
    vector<string> results((istream_iterator<string>(iss)),
                            istream_iterator<string>());
    return results;
}

void split2(const string& str)
{
    stringstream ss(str);
    string token;
    vector<int> results;
    while(getline(ss,token,'/')){   // The demiliter is defined by users
        results.push_back(stoi(token));
    }
    int lengthV = results.size();
    for (int i = 0; i < lengthV; i++){
        cout << results[i] << endl;
    }
}


void split3(const string& str)
{
    vector<string> tokens;
    size_t current, previous = 0;
    current = str.find('/');
    while (current != string::npos) {
        tokens.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find('/', previous);
    }
    tokens.push_back(str.substr(previous, current - previous));
    int lengthV = tokens.size();
    for (int i = 0; i < lengthV; i++){
        cout << tokens[i] << endl;
    }
}

void split4(const string& str)
{
    vector<string> tokens;
    size_t current, previous = 0;
    current = str.find_first_of('/');
    while (current != string::npos) {
        tokens.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find_first_of('/', previous);
    }
    tokens.push_back(str.substr(previous, current - previous));
    int lengthV = tokens.size();
    for (int i = 0; i < lengthV; i++){
        cout << tokens[i] << endl;
    }
}



int main()
{
    /*  split1 method
    string str = "2015\t09\n21";
    vector<string> results  = split1(str);
    int lengthVector = results.size();
    for(int i = 0; i < lengthVector; i++){
        cout << results[i]<< endl;
    }
    */

    /* split2 method
    string str = "2015/09/21";
    split2(str);
    */

    /* split3 method
    string str = "2015/09/21";
    split3(str);
    */

    string str = "2015/09/21";
    split4(str);
}

