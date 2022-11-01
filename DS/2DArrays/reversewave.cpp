#include<bits/stdc++.h>
using namespace std;

void reversewave(int arr[][10],int n,int m){
	int startcol=0,startrow=0,endrow=n-1,endcol=m-1;
	
	while(endcol!=startcol){
		for(int row=startrow;row<=endrow;row++){
			cout<<arr[row][endcol]<<" ";
		}
		for(int row=endrow;row>=startrow;row--){
			cout<<arr[row][endcol-1]<<" ";
		}
		endcol--;
	}
}

int main(){
	int arr[10][10]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	
	int n=4,m=4;
	
	reversewave(arr,n,m);
	return 0;
}
