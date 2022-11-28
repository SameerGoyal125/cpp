#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V];
        }
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        bool checkCycle(int src){
                vector<bool>visited(V,false);
                vector<int>parent(V,0);
                queue<int>q;
                for(int i=0;i<V;i++)parent[i]=i;
                
                q.push(src);
                visited[src]=true;
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(int nbr:l[temp]){
                        if(visited[nbr]==true && parent[temp]!=nbr){
                            return false;}
                        else if(!visited[nbr]){
                            q.push(nbr);
                            visited[nbr]=true;
                            parent[nbr]=temp;
                        }
                    }
                }
                return true;
        }

};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);

    if(g.checkCycle(0))cout<<"Yes it is tree";
    else cout<<"No it is not a tree";
}