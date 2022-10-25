#include <bits/stdc++.h>
using namespace std;

class cab
{
public:
    string name;
    int x, y;
    cab(string name, int x, int y)
    {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    int dist() const
    {
        return x * x + y * y;
    }
};

class cabcomp
{
public:
    bool operator()(const cab A, const cab B)
    {
        return A.dist() < B.dist();
    }
};

void printNearestCabs(vector<cab> cabs, int k)
{
    priority_queue<cab, vector<cab>, cabcomp> max_heap(cabs.begin(), cabs.begin() + k);

    for (int i = k; i < cabs.size(); i++)
    {
        auto Cab = cabs[i];
        if (Cab.dist() < max_heap.top().dist())
        {
            max_heap.pop();
            max_heap.push(Cab);
        }
    }

    while(!max_heap.empty()){
        cout<<max_heap.top().name<<endl;
        max_heap.pop();
    }
    return;
}

int main()
{
    int n, k;
    cin >> n >> k;

    string name;
    int x, y;

    vector<cab> cabs;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> x >> y;
        cab Cab(name, x, y);
        cabs.push_back(Cab);
    }
    printNearestCabs(cabs, k);
    return 0;
}