#include<bits/stdc++.h>
using namespace std;

void generateBrackets(string out,int n,int open,int close,int i){
    if(i==2*n){
        cout<<out<<endl;
        return ;
    }
    if(open<n){
        generateBrackets(out+"(",n,open+1,close,i+1);
    }
    if(close<open){
        generateBrackets(out+")",n,open,close+1,i+1);
    }
}

int main()
{
    string output;
    int n;
    cin>>n;
    generateBrackets(output,n,0,0,0);
    return 0;
}