#include<bits/stdc++.h>
using namespace std;

string spells[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void printspell(int n){
	if(n==0){
		return;
	}
	
	int lastdigit=n%10;
	printspell(n/10);
	cout<<spells[lastdigit]<<" ";
}

int main(){
	int n;
	cin>>n;
	printspell(n);
	return 0;
}
