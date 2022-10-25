#include<bits/stdc++.h>
using namespace std;

bool isSafe(int mat[][9],int i,int j,int num){
    for(int k=0;k<9;k++){
        if(mat[k][j]==num or mat[i][k]==num){
            return false;
        }
    }

    int sx=(i/3)*3;
    int sy=(j/3)*3;

    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(mat[x][y]==num){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
    if(i==n){
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<mat[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }

    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }

    for(int num=1;num<=n;num++){
        if(isSafe(mat,i,j,num)){
            mat[i][j]=num;
            bool solved=solveSudoku(mat,i,j+1,n);
            if(solved){
                return true;
            }            
        }
    }
    mat[i][j]=0;
    return false;
}

int main()
{
    int n=9;
    int mat[9][9]=
    {{0,0,0,0,2,0,0,0,0},
    {7,0,6,4,0,9,0,0,0},
    {0,3,0,0,0,0,6,4,1},
    {0,7,0,0,0,0,3,0,6},
    {3,0,0,0,1,0,0,5,0},
    {0,5,0,0,0,0,0,0,9},
    {0,0,3,1,0,0,0,0,5},
    {0,0,7,0,8,0,0,0,2},
    {0,0,1,5,0,7,4,3,0}};

    if(!solveSudoku(mat,0,0,n)){
        cout<<"No solution exists!"<<endl;
    }

    return 0;
}