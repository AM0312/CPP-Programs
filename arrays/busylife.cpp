#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}


int countActivities(vector<pair<int,int> > activities){
    sort(activities.begin(),activities.end(),compare);
    int count = 1;
    int finish = activities[0].second;
    
    for(int i=1;i<activities.size();i++){
        if(activities[i].first>=finish){
            count++;
            finish = activities[i].second;
        }
    }
    return count;
}

int main(){
    vector<pair<int,int> > activities{{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    cout<<countActivities(activities);
    return 0;
}