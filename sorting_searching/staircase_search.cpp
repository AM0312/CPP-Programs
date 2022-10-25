#include<bits/stdc++.h>
using namespace std;

pair<int,int> search(int m,int n,vector<vector<int> > v,int k){
    int i=m-1;
    int j=0;
    while(i>=0 and j<n){
        if(v[i][j]==k){
            break;
        }
        else if(v[i][j]<k){
            j++;
        }
        else{
            i--;
        }
    }
    pair<int,int> p={i,j};
    return p;
}

int main()
{
    int m,n,k;
    cin>>m>>n;
    vector<vector<int> > v(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cin>>k;
    pair<int,int> ans=search(m,n,v,k);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}