#include<bits/stdc++.h>
using namespace std;

int power(int a,int n){
	if(n==0){
		return 1;
	}
	return a*power(a,n-1);
}

int powerop(int a,int n){
	if(n==0){
		return 1;
	}
	int subprob=powerop(a,n/2);
	int subprobsq=subprob*subprob;
	
	if(n&1){
		return a*subprobsq;
	}
	return subprobsq;
}

int main(){
	int a,n;
	cin>>a>>n;
	cout<<power(a,n)<<endl;
	cout<<powerop(a,n)<<endl;
	return 0;
}
