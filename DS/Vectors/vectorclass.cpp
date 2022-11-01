#include<bits/stdc++.h>
#include "vector.h"
using namespace std;



int main(){
	vect<int> v;
	
	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(5);
	
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
}
