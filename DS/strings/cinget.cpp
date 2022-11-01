#include<iostream>
using namespace std;

int main(){
	char sentence[1000];
	int len=1;	
	char temp=cin.get();
	while(temp!='\n'){
		len++;
		cout<<temp;
		temp=cin.get();
	}
	return 0;
}
