#include<bits/stdc++.h>
using namespace std;


int main(){

    string str;
    getline(cin,str);

    stringstream ss(str);
    vector<string> tokens;
    string token;
    while(getline(ss,token,' ')){
        tokens.push_back(token);
    }
    for(auto token:tokens){
        cout<<token<<",";
    }
    return 0;
}