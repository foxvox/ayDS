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
        // �׷������� ��带 1, 2, 3, ..., n���� �ٷ�� �ʹٸ� 
        // adjList[1]���� adjList[n]���� �����ؾ� �ϹǷ�
        // ũ�⸦ n + 1�� �����ؾ� adjList[n]���� �����ϰ� ������ �� �־��. 
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
        // ��������� ȣ���� ���̱� ������ �Լ� ���� �� �湮 üũ�ص�. 
        visited[node] = true;
        cout << "Visited: " << node << endl; 

        // 1->2�� ���� ��, adjList[node]�� ������ �迭�� �ǹ��Ѵ�. ���� ��� adjList[1]���� {2, 3} �̷��� ��� �ִ�. 
        for (int neighbor : adjList[node]) 
        { 
            // 2->4�� ���� and 4->8�� ���� => ���� �߿� �湮�ߴ� ����� ��� skip 
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
