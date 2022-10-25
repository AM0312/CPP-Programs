#include<bits/stdc++.h>
using namespace std;

string compressString(const string &str){
    int n = str.length();
    string output;
    for (int i = 0; i < n; i++) {
        int count = 1;
 
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        output += str[i];
        output += to_string(count);
    }
    if(output.length()>str.length()){
        return str;
    }
    return output;
}


int main()
{
    string input;
    cin>>input;
    cout<<compressString(input);
    return 0;
}