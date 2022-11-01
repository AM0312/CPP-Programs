#include<bits/stdc++.h>
#include<vector>
using namespace std;
 


int main() {
  
    while(true){
        int width,height,number;
        cout<<"Enter width of board"<<endl;
        cin>>width;
        cout<<endl<<"Enter length of board"<<endl;
        cin>>height;
        cout<<endl<<"Enter number of towers"<<endl;
        cin>>number;
        vector<int> a;
        vector<int> b;
        a.push_back(0);
        b.push_back(0);
        for(int i=0;i<number;i++){
            int x,y;
            cout<<endl<<"Enter co-ordinates of tower number "<<i+1<<endl;
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }
        a.push_back(width+1);
        b.push_back(height+1);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int mx = 0,my = 0;
        for(int i=0;i<a.size()-1;i++){
            mx = max(mx,a[i+1]-a[i]-1);
            my = max(my,b[i+1]-b[i]-1);
        }
        cout<<"Area of largest undefended rectangle is "<<mx*my<<endl;
        break;
    }

    return 0;
}

