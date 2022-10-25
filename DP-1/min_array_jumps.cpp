#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int> arr,vector<int> dp,int i=0){
    int n=arr.size();
    if(i==n-1) return 0;
    if(i>=n) return INT_MAX;
    if(dp[i]!=0) return dp[i];

    int steps=INT_MAX;
    int max_jump=arr[i];

    for(int jump=1;jump<=max_jump;jump++){
        int next=i+jump;
        int subprob=minJumps(arr,dp,next);
        if(subprob!=INT_MAX) steps=min(steps,subprob+1);
    }
    return dp[i]=steps;
}

int main(){
    vector<int> arr{3,4,2,1,2,3,7,1,1,3};
    vector<int> dp(arr.size(),0);
    cout<<minJumps(arr,dp);
    return 0;
}