#include<bits/stdc++.h>
using namespace std;

int friendsparty(int n){
	if(n==1 or n==0){
		return 1;
	}
	return friendsparty(n-1)+(n-1)*friendsparty(n-2);
}

int main(){
	int n;
	cin>>n;
	cout<<friendsparty(n);
	return 0;
}
