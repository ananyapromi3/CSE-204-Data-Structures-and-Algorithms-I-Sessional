#include <iostream>
#include "Graph.cpp"
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Graph *g;
    int n, m, s;
    cin >> n >> m;
    g = new Graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g->addEdge(u, v);
    }
    cin >> s;
    // g->BFS(s);
    // g->TreeBSF();
    // g->DFS(s);
    // g->TreeDSF();
    if (g->ifBipartite())
    {
        cout << "Graph is Bipartite\n";
    }
    else
    {
        cout << "Graph is not Bipartite\n";
    }
    // BFS
    // g->addEdge(1, 0);
    // g->addEdge(1, 5);
    // g->addEdge(5, 2);
    // g->addEdge(5, 6);
    // g->addEdge(0, 4);
    // g->addEdge(2, 3);
    // g->addEdge(6, 7);
    // g->addEdge(6, 2);
    // g->addEdge(3, 7);
    // g->BFS(1);
    // g->TreeBSF();
    // DFS
    // g->addEdge(0, 1);
    // g->addEdge(2, 1);
    // g->addEdge(0, 3);
    // g->addEdge(3, 5);
    // g->addEdge(6, 5);
    // g->addEdge(3, 6);
    // g->addEdge(5, 0);
    // g->addEdge(0, 6);
    // g->addEdge(1, 6);
    // g->addEdge(1, 4);
    // g->addEdge(2, 4);
    // g->addEdge(2, 7);
    // g->addEdge(4, 6);
    // g->addEdge(7, 6);
    // g->addEdge(8, 9);
    // g->DFS(0);
    // g->DFS();
}

// 8 9
// 1 0
// 1 5
// 5 2
// 5 6
// 0 4
// 2 3
// 6 7
// 6 2
// 3 7
// 1

// 10 15
// 0 1
// 2 1
// 0 3
// 3 5
// 6 5
// 3 6
// 5 0
// 0 6
// 1 6
// 1 4
// 2 4
// 2 7
// 4 6
// 7 6
// 8 9
// 0

// 6 6
// 0 1
// 0 2
// 1 3
// 3 4
// 4 5
// 5 3
// 0