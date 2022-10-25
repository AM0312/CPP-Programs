#include<bits/stdc++.h>
using namespace std;

int count_triangles(vector<pair<int,int> > &points){
    unordered_map<int,int> freq_x,freq_y;

    for(auto p:points){
        int x=p.first,y=p.second;
        freq_x[x]++;
        freq_y[y]++;
    }

    int count=0;
    for(auto p:points){
        int x=p.first,y=p.second;

        int fx=freq_x[x],fy=freq_y[y];
        if(fx>=1 and fy>=1) count+=(fx-1)*(fy-1);
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    vector<pair<int,int> > points;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }

    cout<<count_triangles(points);
    return 0;
}