#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Car{
public:
    string id;
    int x,y;
    Car(string id,int x,int y){
        this->id=id;
        this->x=x;
        this->y=y;
    }
    int dist() const{
        return x*x+y*y;
    }
};

class CarCompare{
public:
    bool operator()(const Car A,const Car B){
        return A.dist() <B.dist();//max heap
    }
};

bool distCompare(Car A,Car B){
    return A.dist()<B.dist();
}

void printNearestcars(vector<Car> cars,int k){
    priority_queue<Car,vector<Car>, CarCompare>max_heap(cars.begin(),cars.begin()+k) ;
    for(int i=k;i<cars.size();i++){
        auto car=cars[i];

        if(car.dist()<max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(car);
        }
    }
    vector<Car> output; 
    while(!max_heap.empty()){
        //cout<<max_heap.top().id<<endl;
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    sort(output.begin(),output.end(),distCompare());

    for(auto car:output){
        cout<<car.id<<endl;
    }
    return;
}

int main(){
    int n,k;
    cin>>n>>k;

    string id;
    int x,y;

    vector<Car> cars;

    for(int i=0;i<n;i++){
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    printNearestcars(cars,k);
    return 0;
}

