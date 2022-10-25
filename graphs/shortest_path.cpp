#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir) l[j].push_back(i);
    }

    // void printAdjList(){
    //     for(int i=0;i<V;i++){
    //         cout<<i<<"-->";
    //         for(auto node:l[i]){
    //             cout<<node<<",";
    //         }
    //         cout<<endl;
    //     }
    // }

    void bfs(int source,int dest=-1){
        queue<int> q;
        bool *visited=new bool[V]{0};
        int *dist=new int[V]{0};
        int *parent=new int[V];

        for(int i=0;i<V;i++){
            parent[i]=-1;
        }

        q.push(source);
        visited[source]=true;
        parent[source]=source;
        dist[source]=0;

        while(!q.empty()){
            int f=q.front();
            q.pop();

            for(auto nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr]=f;
                    dist[nbr]=dist[f]+1;
                    visited[nbr]=true;
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<"Shortest distance to node "<<i<<" is "<<dist[i]<<endl;
        }
        if(dest!=-1){
            int temp=dest;
            while(temp!=source){
                cout<<temp<<"--";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }
    }
};

int main(){
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(2,3);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs(1,6);

    // g.printAdjList();

    return 0;
}