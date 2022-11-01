#include<bits/stdc++.h>
#include"hashtable.h"
using namespace std;

int main(){
    Hashtable<int> h;
    h.insert("Mango",100);
    h.insert("Apple",120);
    h.insert("Banana",140);
    h.insert("Orange",200);
    h.insert("Papaya",150);
    h.insert("Kiwi",220);
    h.insert("Cherry",250);
    h.print();

    string fruit;
    cin>>fruit;

    int* price=h.search(fruit);
    if(price!=NULL){
        cout<<"Price of fruit is "<<*price<<endl;
    }
    return 0;
}