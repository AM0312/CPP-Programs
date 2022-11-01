#include<bits/stdc++.h>
using namespace std;

void setithbit(int &n,int i){
	int mask=1<<i;
	n=n|mask;
} 

int main(){
	int n=5;
	int i;
	cin>>i;
	setithbit(n,i);
	cout<<n;
}
