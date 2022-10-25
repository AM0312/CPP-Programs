#include<bits/stdc++.h>
using namespace std;

string unique_substring(string str){
    int i=0;
    int j=0;
    int wlen=0;
    int maxw=0;
    int wstart=-1;

    unordered_map<char,int> m;

    while(j<str.length()){
        char ch=str[j];

        if(m.count(ch) and m[ch]>=i){
            i=m[ch]+1;
            wlen=j-i;
        }

        m[ch]=j;
        wlen++;
        j++;

        if(wlen>maxw){
            maxw=wlen;
            wstart=i;
        }

    }
    return str.substr(wstart,maxw);
}

int main()
{
    string input;
    cin>>input;

    cout<<unique_substring(input);
    return 0;
}