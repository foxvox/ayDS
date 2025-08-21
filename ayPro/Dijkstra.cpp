#include <iostream>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

#define SIZE 6
const int INF = numeric_limits<int>::max();

class Dijkstra
{
private:
    int graph[SIZE][SIZE] = {
        {  0,    2,   5,   1, INF, INF },
        {  2,    0,   3,   3, INF, INF },
        {  5,    3,   0,   3,   1,   6 },
        {  1,    2,   3,   0,   1, INF },
        { INF, INF,   1,   1,   0,   2 },
        { INF, INF,   5, INF,   2,   0 }
    };

    vector<int>    dist;      // 시작점으로부터의 최단 거리
    vector<int>    prev;      // 경로 복원을 위한 이전 노드
    vector<bool>   visited;   // 방문 처리

public:
    Dijkstra()
        : dist(SIZE), prev(SIZE), visited(SIZE)
    {
    }

    // 미방문 노드 중 dist가 최소인 노드의 인덱스를 반환
    // 더 이상 유효한 노드가 없으면 -1 반환
    int Find() const
    {
        int u = -1, minD = INF;
        for (int i = 0; i < SIZE; ++i)
        {
            if (!visited[i] && dist[i] < minD)
            {
                minD = dist[i];
                u = i;
            }
        }
        return u;
    }

    void Update(int start)
    {
        fill(dist.begin(), dist.end(), INF);
        fill(prev.begin(), prev.end(), -1);
        fill(visited.begin(), visited.end(), false);

        dist[start] = 0;

        for (int iter = 0; iter < SIZE; ++iter)
        {
            // 1) 다음으로 방문할 노드를 Find로 구한다
            int u = Find();
            if (u < 0)
                break;            // 더 이상 연결된 노드가 없으면 종료 

            visited[u] = true;

            // 2) u를 경유지로 하여 인접 노드들의 dist 갱신
            for (int v = 0; v < SIZE; ++v)
            {
                if (!visited[v] && graph[u][v] != INF)
                {
                    int nextD = dist[u] + graph[u][v];
                    if (nextD < dist[v])
                    {
                        dist[v] = nextD;
                        // 출력에서 경로 복원을 위한 이전 노드 
                        prev[v] = u;
                    }
                }
            }
        }
    }

    // 경로 및 최단 거리를 출력
    void PrintPaths(int start) const
    {
        for (int i = 0; i < SIZE; ++i)
        {
            cout << "노드 " << (start + 1)
                << " → 노드 " << (i + 1)
                << " 최단 거리: ";

            if (dist[i] == INF)
            {
                cout << "도달 불가\n";
                continue;
            }

            cout << dist[i] << ", 경로: ";
            stack<int> stk;
            for (int v = i; v != -1; v = prev[v])
                stk.push(v);

            while (!stk.empty())
            {
                cout << (stk.top() + 1);
                stk.pop();
                if (!stk.empty()) cout << " → ";
            }
            cout << "\n";
        }
    }

    // 특정 노드(target)의 최단 거리를 반환
    int GetDistance(int target) const
    {
        return dist[target];
    }
};

int main()
{
    Dijkstra solver;
    int start = 0;  // 노드 1 (index 0)

    solver.Update(start);
    solver.PrintPaths(start);

    cout << "\n노드 1 → 노드 6 최단 거리: "
        << solver.GetDistance(5) << "\n";

    return 0;
}
