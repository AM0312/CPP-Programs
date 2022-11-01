#include<iostream>
using namespace std;

int main(){
	char sentence[1000];
	int digcount=0,spcount=0;	
	char temp=cin.get();
	while(temp!='\n'){
		if(temp==' '){
			spcount++;
		}
		if(temp>='0' and temp<='9'){
			digcount++;
		}
		temp=cin.get();
	}
	cout<<"Number of digits is "<<digcount<<",number of spaces is"<<spcount<<endl;
	return 0;
}
