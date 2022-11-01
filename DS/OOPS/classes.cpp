#include<bits/stdc++.h>
using namespace std;

class product{
    int id;
    int mrp;
    char name[100];
    int sp;
public:
    void setMrp(int price){
        mrp=price;
    }
    void setSp(int price){
        if(price>mrp){
            sp=mrp;
        }
        else{
            sp=price;
        }
    }
    int getMrp(){
        return mrp;
    }
    int getSp(){
        return sp;
    }
};

int main(){
    product camera;
    camera.setMrp(100);
    camera.setSp(200);   
    cout<<camera.getMrp()<<endl<<camera.getSp();
    return 0;
}