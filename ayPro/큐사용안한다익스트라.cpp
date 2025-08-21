#include <iostream>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

#define SIZE 6
const int INF = numeric_limits<int>::max();

class Dijkstra {
private:
    int graph[SIZE][SIZE] = {
        {  0,    2,   5,   1, INF, INF },
        {  2,    0,   3,   3, INF, INF },
        {  5,    3,   0,   3,   1,   6 },
        {  1,    2,   3,   0,   1, INF },
        { INF, INF,   1,   1,   0,   2 },
        { INF, INF,   5, INF,   2,   0 }
    };

    vector<int> dist;
    vector<int> prev;

public:
    Dijkstra() {
        dist.resize(SIZE);
        prev.resize(SIZE);
    }

    /// 순차 탐색 기반 다익스트라 
    void Update(int start) 
    {
        vector<bool> visited(SIZE, false);
        fill(dist.begin(), dist.end(), INF);
        fill(prev.begin(), prev.end(), -1);
        dist[start] = 0;

        for (int iter = 0; iter < SIZE; ++iter) 
        {
            // 1) 아직 방문하지 않은 노드 중 dist가 최소인 노드를 찾는다
            int u = -1, minDist = INF;
            for (int i = 0; i < SIZE; ++i) 
            {
                if (!visited[i] && dist[i] < minDist) 
                {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;  // 더 이상 도달 가능한 노드 없음

            visited[u] = true;

            // 2) 선택된 u를 통해 다른 노드의 거리 갱신
            for (int v = 0; v < SIZE; ++v) {
                if (!visited[v] && graph[u][v] != INF) {
                    int nextDist = dist[u] + graph[u][v];
                    if (nextDist < dist[v]) {
                        dist[v] = nextDist;
                        prev[v] = u;
                    }
                }
            }
        }
    }

    void PrintPaths(int start) const {
        for (int i = 0; i < SIZE; ++i) {
            cout << "노드 " << (start + 1)
                << " → 노드 " << (i + 1)
                << " 최단 거리: ";

            if (dist[i] == INF) {
                cout << "도달 불가\n";
                continue;
            }

            cout << dist[i] << ", 경로: ";
            stack<int> stk;
            for (int v = i; v != -1; v = prev[v])
                stk.push(v);

            while (!stk.empty()) {
                cout << (stk.top() + 1);
                stk.pop();
                if (!stk.empty()) cout << " → ";
            }
            cout << "\n";
        }
    }

    int Find(int target) const 
    {
        return dist[target];
    }
};

int main() {
    Dijkstra solver;
    int start = 0;  // 노드 1 (index 0)
    solver.Update(start);
    solver.PrintPaths(start);

    cout << "\n노드 1 → 노드 6 최단 거리: "
        << solver.Find(5) << "\n";

    return 0;
}
