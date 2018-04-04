#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph{
    public:
        int n;
        vector< vector<int> > adj;
        vector<bool> visited;

        Graph()
            :n(0)
        {

        }
        Graph(int n)
            :n(n)
        {
            adj.resize(n);
            visited.resize(n);
        }

        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void sortList()
        {
            for(int i=0; i<n; i++)
                sort(adj[i].begin(), adj[i].end());
        }

        void dfs()
        {
            fill(visited.begin(), visited.end(), false);
            dfs(0);
        }

        int dfs_all()
        {
            int components = 0;
            fill(visited.begin(), visited.end(), false);
            for(int i=0; i<n; i++)
            {
                if(!visited[i])
                {
                    cout << "-- new DFS begins --" << endl;
                    cout << "The num of vertex: " << dfs(i) << endl;
                    components++;
                }
            }
            return components;
        }

    private:
        int dfs(int curr)
        {
            int count = 1;
            visited[curr] = true;
            cout << "node " << curr << " visited" << endl;
            for(int next: adj[curr])
            {
                if(!visited[next])
                {
                    count += dfs(next);
                }
            }
            return count;
        }
};

int main()
{
    Graph G(9);
    G.addEdge(0,1);
    G.addEdge(1,3);
    G.addEdge(2,3);
    G.addEdge(4,6);
    G.addEdge(5,7);
    G.addEdge(5,8);
    G.addEdge(7,8);
    G.sortList();
    //G.dfs();
    cout << "The number of component is " << G.dfs_all() << endl;

    return 0;
}
