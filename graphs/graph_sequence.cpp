#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > matrix,vector<vector<bool> > &visited,vector<vector<int> > &cache,int i,int j,int m,int n){
    visited[i][j]=true;

    int dx[]={-1,1,0,0};
    int dy[]={0,0,1,-1};

    int cnt=0;
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];

        if(nx>=0 and ny>=0 and nx<m and ny<n and matrix[nx][ny]>matrix[i][j]){
            if(visited[nx][ny]) cnt=max(cnt,1+cache[nx][ny]);
            else{
                dfs(matrix,visited,cache,nx,ny,m,n);
                cnt=max(cnt,1+cache[nx][ny]);
            }
        }
    }
    cache[i][j]=cnt;
    return;
}

int longestPathSequence(vector<vector<int> > matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<bool> > visited(m+1,vector<bool>(n+1,false));
    vector<vector<int> > cache(m+1,vector<int>(n+1,0));
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dfs(matrix,visited,cache,i,j,m,n);
            ans=max(ans,cache[i][j]);
        }
    }
    return ans+1;
}
int main(){}