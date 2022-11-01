#include<bits/stdc++.h>
using namespace std;

int fact(int i){
	if(i==1){
		return 1;
	}
	return i*fact(i-1);
}

int gridways(int i,int j,int m,int n){
	if(i==m-1 and j==n-1){
		return 1;
	}
	if(j>=n or i>=m){
		return 0;
	}
	int ans=gridways(i+1,j,m,n)+gridways(i,j+1,m,n);
	return ans;
}

int gridways_trick(int m,int n){
	return fact(m+n-2)/(fact(m-1)*fact(n-1));
}

int main(){
	int m,n;
	cin>>m>>n;
	cout<<"Actual:"<<gridways(0,0,m,n)<<endl;
	cout<<"Trick:"<<gridways_trick(m,n);
	return 0;
}
