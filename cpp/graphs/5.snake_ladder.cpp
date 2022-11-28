#include <bits/stdc++.h>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
    }
    void board(T src,T dest)
    {
        map<T, int> depth;
        map<T,T>parent;
        parent[src]=src;
        queue<T> q;
        for (auto i : l)
        {
            depth[i.first] = INT_MAX;
        }
        depth[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (int nbr : l[node])
            {
                if (depth[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    depth[nbr] = depth[node] + 1;
                    parent[nbr]=node;
                }
            }
        }
        T temp=dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        cout<<src;
    
    }
};
int main()
{
    Graph<int> g;
    vector<int> jump(50, 0);
    jump[2] = 13;
    jump[5] = 2;
    jump[9] = 18;
    jump[18] = 11;
    jump[17] = -13;
    jump[20] = -14;
    jump[24] = -8;
    jump[25] = 10;
    jump[32] = -2;
    jump[34] = -22;
    for(int j=0;j<=36;j++){
        for(int i=1;i<=6;i++){
        int q=j+i+jump[j+i];
        if(q<=36){
            g.addEdge(j,q);
        }
    }
    }
    g.addEdge(36,36);

    g.board(0,36);
    
    return 0;
}