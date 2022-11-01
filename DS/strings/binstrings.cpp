#include<bits/stdc++.h>
using namespace std;

int binstrings(int n){
	if(n==0){
		return 1;
	}
	if(n==1){
		return 2;
	}
	return binstrings(n-1)+binstrings(n-2);
}

int main(){
	int n;
	cin>>n;
	cout<<binstrings(n);
	return 0;
}
