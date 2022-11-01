#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int> arr) {
	int maxele=arr[0];
    for(int i=0;i<arr.size();i++){
        if (arr[i]>maxele){
            maxele=arr[i];
        }
    }
    return maxele;
}

int main(){
    vector<int> arr[]={1,3,5,12,43,3,134};
    cout<<"max value of the elements is"<<largestElement(arr)<<endl;
    return 0;
}
