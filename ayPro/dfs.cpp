#include <iostream>
#include <vector>
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
        // 그래프에서 노드를 1, 2, 3, ..., n으로 다루고 싶다면 
        // adjList[1]부터 adjList[n]까지 접근해야 하므로
        // 크기를 n + 1로 설정해야 adjList[n]까지 안전하게 접근할 수 있어요. 
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
        // 재귀적으로 호출할 것이기 때문에 함수 진입 후 방문 체크해둠. 
        visited[node] = true;
        cout << "Visited: " << node << endl; 

        // 1->2로 진행 후, adjList[node]는 각각의 배열을 의미한다. 예를 들어 adjList[1]에는 {2, 3} 이렇게 들어 있다. 
        for (int neighbor : adjList[node]) 
        { 
            // 2->4로 진행 and 4->8로 진행 => 진행 중에 방문했던 노드인 경우 skip 
            if (!visited[neighbor]) 
            {
                dfs(neighbor); 
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

    g.dfs(1);

    return 0;
}
