#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    vector<int> arr{1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}