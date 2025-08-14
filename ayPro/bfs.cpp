#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int                  numNodes;
    vector<vector<int>>  adjList;
    vector<bool>         visited;

public:
    Graph(int n) : numNodes(n)
    {
        adjList.resize(n + 1);
        visited.resize(n + 1, false);
    }

    void addEdge(int u, int v, bool undirected = true)
    {
        adjList[u].push_back(v);
        if (undirected)
        {
            adjList[v].push_back(u);
        }
    }

    void dfs(int node)
    {
        visited[node] = true;
        cout << "DFS Visited: " << node << endl;

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor); 
            }
        }
    }

    void bfs(int start)
    {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            // 여기서 bfs 출력이 이루어 진다. 
            cout << "BFS Visited: " << node << endl;

            // 5, 6, 7은 요소를 갖고 있지 않아서 for 문 실행이 안 됨. 
            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void resetVisited()
    {
        fill(visited.begin(), visited.end(), false);
    }
};

int main()
{
    Graph g(30);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    g.addEdge(4, 9);

    cout << "=== DFS ===" << endl;
    g.dfs(1);

    g.resetVisited();

    cout << "\n=== BFS ===" << endl;
    g.bfs(1);

    return 0;
}
