#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySort_one(vector<int> arr){

    vector<int> b(arr);
    sort(b.begin(),b.end());

    int i=0;
    int n=arr.size();

    while(i<n and arr[i]==b[i]){
        i++;
    }

    int j=arr.size()-1;
    while(j>=0 and arr[j]==b[j]){
        j--;
    }

    if(i==n){
        return {-1,-1};
    }
    return {i,j};
}

bool outoforder(vector<int> arr,int i){
    int x=arr[i];
    if(i==0){
        return x>arr[1];
    }
    if(i==arr.size()-1){
        return x<arr[i-1];
    }

    return x>arr[i+1] or x<arr[i-1];
}

vector<int> subarraySort_Two(vector<int> arr){
    int smallest=INT_MAX;
    int largest=INT_MIN;

    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        if(outoforder(arr,i)){
            largest=max(largest,x);
            smallest=min(smallest,x);
        }
    }
    if(smallest==INT_MAX){
        return {-1,-1};
    }

    int left=0;
    while(smallest>=arr[left]){
        left++;
    }
    int right=arr.size()-1;
    while(largest<=arr[right]){
        right--;
    }
    return {left,right};
}

int main(){
    vector<int> arr{1,2,3,4,5,8,7,6,9,10};
    vector<int> ans=subarraySort_one(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl<<endl;
    vector<int> res=subarraySort_Two(arr);
    for(auto x:res){
        cout<<x<<" ";
    }

    return 0;
}