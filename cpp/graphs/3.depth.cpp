#include <bits/stdc++.h>
#include <queue>
using namespace std;
template <typename T>
class Graph{
    map<T, list< T> > l;

public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void depth(T src){
        map<T, int> depth;
        queue<T> q;
        for(auto i:l){
            depth[i.first]=INT_MAX;
        }
        depth[src]=0;
        q.push(src);
        while (!q.empty()){
            T node = q.front();
            q.pop();
            for (int nbr : l[node])
            {
                if (depth[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    depth[nbr]=depth[node]+1;
                }    
            }
        }
        for(auto i:depth){
            cout<<"Dist from "<<src<<" to "<<i.first<<" is "<<i.second<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.depth(0);
    return 0;
}