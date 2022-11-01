#include<bits/stdc++.h>
using namespace std;

int tilingproblem(int n){
	if(n==0 or n==1 or n==2 or n==3){
		return 1;
	}
	return tilingproblem(n-1)+tilingproblem(n-4);
}

int main(){
	int n;
	cin>>n;
	cout<<tilingproblem(n);
	return 0;
}
