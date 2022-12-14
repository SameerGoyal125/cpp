#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int>*l;
    int V;
    public:
        Graph(int V){
            this->V=V;
            l = new list<int>[V];
        }
        void addEdge(int x,int y){
            l[x].push_back(y);
        }
        void topological(){
           vector<int>inorder(V,0);
           for(int i=0;i<V;i++){
                for(auto nbr:l[i]){
                inorder[nbr]++;
            }
           }
           queue<int>q;
           for(int i=0;i<V;i++){
            if(inorder[i]==0)q.push(i);
           }
           while(!q.empty()){
                int node=q.front();
                q.pop();
                cout<<node<<" ";
                for(auto nbr:l[node]){
                    inorder[nbr]--;
                    if(inorder[nbr]==0)q.push(nbr);
                }
           }
        }
};
int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.topological();
}