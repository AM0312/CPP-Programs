#include<bits/stdc++.h>
using namespace std;

int countWays(int n,int k){
    if(n==0) return 1;
    if(n<0) return 0;

    int ans=0;
    for(int jump=1;jump<=k;jump++){
        ans+=countWays(n-jump,k);
    }
    return ans;
}

int countWaysDPTopDown(int n,int k,int *dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=0) return dp[n];

    int ans=0;
    for(int jump=1;jump<=k;jump++){
        ans+=countWaysDPTopDown(n-jump,k,dp);
    }
    return dp[n]=ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    int dp[1000]={0};
    cout<<countWaysDPTopDown(n,k,dp)<<endl;
    return 0;
}