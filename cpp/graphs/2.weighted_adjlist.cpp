
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<string, list<pair<string, int > > > l;

public:
    void addEdge(string x, string y, bool bidir, int cost)
    {
        l[x].push_back(make_pair(y, cost));
        if (bidir)
            l[y].push_back(make_pair(x, cost));
    }
    void print()
    {
        for (auto g : l)
        {
            string city = g.first;
            list<pair<string, int > > nbrs = g.second;
            cout << city << "->";
            for (auto nbr : nbrs)
            {
                cout << nbr.first << " " << nbr.second << ",";
            }
            cout << endl;
        }
    }

};
int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "C", true, 10);
    g.addEdge("A", "D", false, 50);
    g.addEdge("B", "D", true, 40);
    g.addEdge("C", "D", true, 30);
    g.print();

        return 0;
}