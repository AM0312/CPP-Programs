#include<bits/stdc++.h>
using namespace std;

int countWaysDPBottomUp(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int jump=1;jump<=k;jump++){
            if(i-jump>=0) dp[i]+=dp[i-jump];
        }
    }
    return dp[n];
}

int countWaysOpt(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;

    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }

    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<countWaysOpt(n,k);
}