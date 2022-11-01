#include<vector>
using namespace std;

template<typename T>
class StackV{
    vector<T> arr;
public:
    void push(T data){
        arr.push_back(data);
    }

    void pop(){
        arr.pop_back();
    }

    T top(){
        int lastidx=arr.size()-1;
        return arr[lastidx];
    }
    
    bool isempty(){
        return arr.size()==0;
    }
};