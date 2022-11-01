#include<bits/stdc++.h>
#include<cstring>
using namespace std;

class product{
    int id;
    int mrp;
    char name[100];
    int sp;
public:
    product(int id,char *n,int mrp,int sp){
        this->id=id;
        this->mrp=mrp;
        this->sp=sp;
        strcpy(name,n);
    }

    product (product &X){
        id=X.id;
        //name=X.name;
        mrp=X.mrp;
        sp=X.sp;
    }
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
    void showdetails(){
        cout<<"Name:"<<name<<endl;
        cout<<"Id:"<<id<<endl;
        cout<<"MRP:"<<mrp<<endl;
        cout<<"Selling Price:"<<sp<<endl;
    }
};

int main(){
    product camera(101,"Gopro",28000,20000);
    camera.showdetails();
   // camera.mrp=100;
   // camera.sp=200;
   // camera.setMrp(100);
   // camera.setSp(200);  
    product webcam(camera); 
    webcam.showdetails();

    product handycam=camera;
    handycam.showdetails();
   // cout<<camera.getMrp()<<endl<<camera.getSp();
    return 0;
}