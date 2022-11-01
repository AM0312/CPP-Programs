#include<bits/stdc++.h>
using namespace std;

void allvowels(char * a){
	char b[100];
	int j=0;
	for(int i=0;i<100;i++){
		if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u')){
			b[j]=a[i];
			j++;
		}
	}
	b[j+1]='\0';
	cout<<b<<endl;;
}

int main(){
	char a[100];
	cout<<"Enter a string"<<endl;
	cin.getline(a,10000);
	allvowels(a);
	return 0;
}
