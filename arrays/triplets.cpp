#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > triplets(vector<int> arr,int sum){
    sort(arr.begin(),arr.end());
    vector<vector<int> > result;
    int n=arr.size();

    for(int i=0;i<=n-3;i++){
        int j=i+1;
        int k=n-1;

        while(j<k){
            int cursum=arr[i];
            cursum+=arr[j];
            cursum+=arr[k];

            if(cursum==sum){
                result.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if(cursum>sum){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return result;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,15};
    int sum=18;

    auto result=triplets(arr,sum);;
    for(auto v:result){
        for(auto n:v){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    return 0;
}