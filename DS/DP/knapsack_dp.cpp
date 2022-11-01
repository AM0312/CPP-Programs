#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int price[],int n,int w){
    vector<vector<int> > dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            int inc=0,exc=0;

            if(wt[i-1]<=j){
                inc=price[i-1]+dp[i-1][j-wt[i-1]];
            }
            exc=dp[i-1][j];

            dp[i][j]=max(inc,exc);
        }
    }
    return dp[n][w];
}



int main(){
    int wts[]={2,7,3,4};
    int prices[]={5,20,20,10};

    int n=4;
    int w=11;

    cout<<knapsack(wts,prices,n,w);
    return 0;
}