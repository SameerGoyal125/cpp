#include <bits/stdc++.h>
#include <queue>
using namespace std;
template <typename T>
class Graph{
    map<T, list< T> > l;
public:
    void addEdge(T x, T y){
        l[x].push_back(y);
    }
    void dfs_helper(T src,map<T, bool>&visited,list<T>&ordering){
        visited[src]=true;  
        for(auto nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited,ordering);
            }
        }
        ordering.push_front(src);
        return;
    }
    void dfs(T src){
        map<T, bool> visited;
        list<T>ordering;
        for(auto node:l){
            visited[node.first]=false;
        }
        for(auto node:l){
            if(!visited[node.first]){
                dfs_helper(node.first,visited,ordering);
            }
        }
        for(auto p:ordering){
            cout<<p<<endl;
        }

    }
};
int main()
{
    Graph<string> g;
    g.addEdge("Python","Data Preprocessing");
    g.addEdge("Python","ML Basics");
    g.addEdge("Python","Pytorch");
    g.addEdge("Data Preprocessing","ML Basics");
    g.addEdge("ML Basics","Deep Learning");
    g.addEdge("Pytorch","Deep Learning");
    g.addEdge("Deep Learning","Face Recognition");
    g.addEdge("Data Set","Face Recognition");

    g.dfs("Python");
    return 0;
}