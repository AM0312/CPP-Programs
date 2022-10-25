#include<bits/stdc++.h>
using namespace std;

void subsequences(string s,string o,vector<string> &v){
    if(s.size()==0){
        v.push_back(o);
        return;
    }
    char ch=s[0];
    string reducedinput=s.substr(1);
    subsequences(reducedinput,o+ch,v);
    subsequences(reducedinput,o,v);
}

bool compare(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1<s2;
    }
    return s1.length()<s2.length();
}

int main()
{
    string s;
    cin>>s;
    vector<string> v;
    string output="";
    subsequences(s,output,v);
    sort(v.begin(),v.end(),compare);
    for(auto x:v){
        cout<<x<<",";
    }
    return 0;
}