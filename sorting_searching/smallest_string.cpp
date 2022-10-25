#include<bits/stdc++.h>
using namespace std;

bool compare(string a,string b){
    return a+b<b+a;
}

int main()
{
    string arr[]={"a","ab","aba"};
    int n=3;

    sort(arr,arr+n,compare);
    for(auto x:arr){
        cout<<x;
    }
    return 0;
}