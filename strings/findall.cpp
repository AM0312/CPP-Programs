#include<bits/stdc++.h>
using namespace std;

vector<int> findall(string big,string small){
    vector<int> res;
    int index=big.find(small);
    while(index!=-1){
        res.push_back(index);
        index=big.find(small,index+1);
    }
    return res;
}

int main(){
    string big="I liked the movie, acting in movie was great!";
    string small="movie";
    vector<int> ans=findall(big,small);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}