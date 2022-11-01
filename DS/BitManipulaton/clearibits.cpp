#include<bits/stdc++.h>
using namespace std;

void clearibits(int &n,int i){
	int mask=(-1<<i);
	n=n&mask;
}

int main(){
	int n=13;
	int i;
	cin>>i;	
	
	clearibits(n,i);
	cout<<n;
	return 0;
	
	
}
