#include<bits/stdc++.h>
using namespace std;

int countbitshack(int n){
	int ans=0;
	while(n>0){
		n=n&(n-1);
		ans++;
	}
	return ans;	
}

int main(){
	int n;
	cin>>n;
	
	cout<<countbitshack(n)<<endl;
	return 0;
}
