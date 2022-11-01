#include<bits/stdc++.h>
using namespace std;

void printboard(int n,int board[][20]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool canPlace(int board[][20],int n,int x,int y){
	for(int k=0;k<x;k++){
		if (board[k][y]==1){
			return false;
		}
	}
	int i=x;
	int j=y;
	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	
	i=x;
	j=y;
	
	while(i>=0 and j<n){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j++;
	}
	return true;
}

int solveNQueen(int n,int board[][20],int i){
	if(i==n){
		//printboard(n,board);
		return 1;
	}
	int ways=0;
	
	for(int j=0;j<n;j++){
		if(canPlace(board,n,i,j)){
			board[i][j]=1;
			ways+=solveNQueen(n,board,i+1);
			//backtrack
			board[i][j]=0;
		}
	}
	return ways;
}

int main(){
	int board[20][20]={0};
	int n;
	cin>>n;
	
	cout<<solveNQueen(n,board,0);
	return 0;
}
