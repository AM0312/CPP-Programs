#include<bits/stdc++.h>
using namespace std;

int coinChangeDPBottomUp(int n,vector<int> coins){
    vector<int> dp(n+1,0);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
        for(int c:coins){
            if(i-c>=0 and dp[i-c]!=INT_MAX) dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    return dp[n]==INT_MAX?  -1:dp[n];
}



int main(){
    int n=15;
    vector<int> coins{1,3,7,10};
    cout<<coinChangeDPBottomUp(n,coins)<<endl;
    // int dp[n+1]={INT_MAX};
    // cout<<coinChangeDPTopDown(n,coins,dp);
    return 0;
}

