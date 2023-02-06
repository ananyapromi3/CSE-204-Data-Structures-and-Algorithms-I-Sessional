#include <iostream>
#include "Arr.cpp"
using namespace std;
class Graph
{
    int vertextCount;
    bool **adjMat;
    int *parent;
    int *dist;
    bool *visited;
    int start;
    int time;
    int *startTime;
    int *endTime;
    int *color;

    void init()
    {
        for (int i = 0; i < vertextCount; i++)
        {
            visited[i] = false;
            dist[i] = INT_MAX;
            parent[i] = i;
            startTime[i] = 0;
            endTime[i] = 0;
        }
    }

public:
    Graph(int vertextCount)
    {
        this->vertextCount = vertextCount;
        adjMat = new bool *[vertextCount];
        parent = new int[vertextCount];
        dist = new int[vertextCount];
        visited = new bool[vertextCount];
        startTime = new int[vertextCount];
        endTime = new int[vertextCount];
        color = new int[vertextCount];
        for (int i = 0; i < vertextCount; i++)
        {
            adjMat[i] = new bool[vertextCount];
        }
        for (int i = 0; i < vertextCount; i++)
        {
            for (int j = 0; j < vertextCount; j++)
            {
                adjMat[i][j] = false;
            }
        }
        start = 0;
    }
    ~Graph()
    {
        for (int i = 0; i < vertextCount; i++)
        {
            delete[] adjMat[i];
        }
        delete[] adjMat;
        delete[] visited;
        delete[] parent;
        delete[] dist;
        vertextCount = 0;
    }
    void addEdge(int v1, int v2)
    {
        adjMat[v1][v2] = true;
    }

    void BFS(int s)
    {
        init();
        dist[s] = 0;
        Queue<int> queue(vertextCount);
        queue.enqueue(s);
        visited[s] = true;
        while (queue.length())
        {
            int u = queue.dequeue();
            for (int i = 0; i < vertextCount; i++)
            {
                if (adjMat[u][i] && !visited[i])
                {
                    queue.enqueue(i);
                    visited[i] = true;
                    parent[i] = u;
                    dist[i] = dist[u] + 1;
                }
            }
        }
    }

    void TreeBSF()
    {
        for (int i = 0; i < vertextCount; i++)
        {
            if (visited[i])
            {
                cout << "Node " << i << ": Parent: " << parent[i] << ", Distance: " << dist[i] << "\n";
            }
            else
            {
                cout << "Node " << i << " unreachable\n";
            }
        }
        cout << "BFS Tree:\n";
        // cout << "Visited nodes: ";
        // for (int i = 0; i < vertextCount; i++)
        // {
        //     if (visited[i])
        //     {
        //         cout << i << " ";
        //     }
        // }
        cout << "Edges: ";
        for (int i = 0; i < vertextCount; i++)
        {
            if (parent[i] != i)
            {
                cout << "(" << parent[i] << ", " << i << ") ";
            }
        }
        cout << "\n";
    }

    void DFS(int s)
    {
        init();
        time = 0;
        while (!visited[s])
        {
            DFS_visit(s);
        }
        for (int u = 0; u < vertextCount; u++)
        {
            if (!visited[u])
            {
                DFS_visit(u);
            }
        }
    }

    void TreeDSF()
    {
        for (int i = 0; i < vertextCount; i++)
        {
            if (visited[i])
            {
                cout << "Node " << i << ": Parent: " << parent[i] << ", Start Time: " << startTime[i] << ", End Time: " << endTime[i] << "\n";
            }
            else
            {
                cout << "Node " << i << " not visited\n";
            }
        }
        cout << "DFS Tree:\n";
        // cout << "Visited nodes: ";
        // for (int i = 0; i < vertextCount; i++)
        // {
        //     if (visited[i])
        //     {
        //         cout << i << " ";
        //     }
        // }
        cout << "Edges: ";
        for (int i = 0; i < vertextCount; i++)
        {
            if (parent[i] != i)
            {
                cout << "(" << parent[i] << ", " << i << ") ";
            }
        }
        cout << "\n";
    }

    void DFS_visit(int u)
    {
        startTime[u] = ++time;
        visited[u] = true;
        for (int v = 0; v < vertextCount; v++)
        {
            if (adjMat[u][v] && !visited[v])
            {
                parent[v] = u;
                DFS_visit(v);
            }
        }
        endTime[u] = ++time;
    }

    bool ifBipartite()
    {
        for (int i = 0; i < vertextCount; i++)
        {
            color[i] = 0;
        }
        Queue<int> queue(vertextCount);
        queue.enqueue(0);
        color[0] = 1;
        while (queue.length())
        {
            int u = queue.dequeue();
            for (int i = 0; i < vertextCount; i++)
            {
                if ((adjMat[u][i] || adjMat[i][u]) && i != u)
                {
                    if (color[i] == 0)
                    {
                        if (color[u] == 1)
                        {
                            color[i] = 2;
                        }
                        else
                        {
                            color[i] = 1;
                        }
                        queue.enqueue(i);
                    }
                    else if (color[i] == color[u])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};