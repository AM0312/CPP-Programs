#include<bits/stdc++.h>
using namespace std;

int rotated_serach(vector<int> a,int key){
    int n=a.size();

    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=(s+e)/2;

        if(a[mid]==key){
            return mid;
        }

        if(a[s]<=a[mid]){
            if(key>=a[s] and key<=a[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        else{
            if(key>=a[mid] and key<=a[e]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a{4,5,6,7,0,1,2,3};
    int key;
    cin>>key;
    cout<<rotated_serach(a,key)<<endl;
    return 0;
}