#include<bits/stdc++.h>
using namespace std;

int maxsubarrsum(vector<int> arr){    
    int max1=0;
    int maxsofar=0;
    for(int i=0;i<arr.size();i++){
        maxsofar+=arr[i];
        if(max1<maxsofar){
            max1=maxsofar;
        }
        if(maxsofar<0){
            maxsofar=0;
        }
    }
    return max1;

}


int main(){
    vector<int> v{-1,-2,-3,-4,-2,-6,-8,-3};
    cout<<maxsubarrsum(v)<<endl;
    return 0;
}