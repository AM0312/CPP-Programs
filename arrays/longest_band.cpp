#include<bits/stdc++.h>
using namespace std;

int longestchain(vector<int> arr){
    int n=arr.size();
    unordered_set<int> s;
    int largest=0;

    for(int x:arr){
        s.insert(x);
    }

    for(auto ele:s){
        int par=ele-1;
        if(s.find(par)==s.end()){
            int next=ele+1;
            int cnt=1;

            while(s.find(next)!=s.end()){
                next++;
                cnt++;
            }
            if(cnt>largest){
                largest=cnt;
            }
        }
    }
    return largest;
    
}


int main(){
    vector<int> arr{1,9,3,0,18,5,2,4,10,12,7,6};

    cout<<longestchain(arr);
    return 0;
}