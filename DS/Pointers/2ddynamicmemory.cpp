#include<bits/stdc++.h>
using namespace std;

int** create2darray(int rows,int cols){
	int** arr=new int*[rows];
	
	for(int i=0;i<rows;i++){
		arr[i]=new int[cols];
	}
	
	int val=0;
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			arr[i][j]=val;
			val++;
		}
	}
	return arr;
}

int main(){
	int rows,cols;
	cin>>rows>>cols;
	
	int** arr=create2darray(rows,cols);
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
