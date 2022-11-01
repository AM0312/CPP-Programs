#include<bits/stdc++.h>
using namespace std;

int main(){
	int x=10;
	cout<<&x<<endl;
	
	int *xp=&x;
	cout<<xp<<endl;
	
	cout<<*xp<<endl;
	
	int *p=0;
	int *q=NULL;
	
	cout<<p;
}
