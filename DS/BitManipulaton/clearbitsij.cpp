#include<bits/stdc++.h>
using namespace std;

void clearbitsij(int &n,int i,int j){
	int a=((~0)<<(j+1));
	int b=((1<<i)-1);
	int mask=a|b;
	n=n&mask;
}
int main(){
	int n=13,i,j;
	cin>>i>>j;
	
	clearbitsij(n,i,j);
	cout<<j;
	return 0;
	
}
