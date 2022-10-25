#include<bits/stdc++.h>
using namespace std;

void printboard(int n,int board[][20]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool canPlace(int board[][20],int n,int i,int j){
    for(int k=0;k<i;k++){
        if(board[k][j]==1){
            return false;
        }
    }

    int x=i,y=j;
    while(x>=0 and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    x=i;
    y=j;
    while(x>=0 and y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    return true;
}

bool solveNQueen(int n,int board[][20],int i){

    if(i==n){
        printboard(n,board);
        return true;
    }

    for(int j=0;j<n;j++){
        if(canPlace(board,n,i,j)){
            board[i][j]=1;
            bool success=solveNQueen(n,board,i+1);
            if(success){
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}

int main()
{
    int board[20][20]={0};
    int n;
    cin>>n;

    solveNQueen(n,board,0);
    return 0;
}