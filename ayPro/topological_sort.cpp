#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DAG means Directed Acyclic Graph 방향성을 가진 비순환적인 그래프 

class Graph
{
private:
    int                 numNodes;
    vector<vector<int>> adjList;
    vector<int>         inDegree;

public:
    Graph(int n) : numNodes(n)
    {
        adjList.resize(n + 1);
        inDegree.resize(n + 1, 0);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    void topologicalSort()
    {
        queue<int>   q;
        vector<int>  result;

        // 진입 차수가 0인 노드를 큐에 삽입
        for (int i = 1; i <= numNodes; ++i) 
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adjList[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // 결과 출력
        if (result.size() == numNodes)
        {
            cout << "Topological Order: ";
            for (int node : result)
            {
                cout << node << " "; 
            }
            cout << endl;
        }
        else
        {
            cout << "Cycle detected! Topological sort not possible." << endl;
        }
    }
};

int main()
{
    Graph g(7);

    g.addEdge(1, 2);
    g.addEdge(1, 5);

    g.addEdge(2, 3);
    g.addEdge(3, 4); 

    g.addEdge(4, 6); 
   
    g.addEdge(5, 6); 
    g.addEdge(6, 7); 

    g.topologicalSort(); 

    return 0;
}
