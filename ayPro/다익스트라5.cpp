#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

#define SIZE 6
const int INF = numeric_limits<int>::max();

class Dijkstra
{
private:
    int graph[SIZE][SIZE] =
    {
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
    void Update(int start)
    {
        dist.assign(SIZE, INF);
        prev.assign(SIZE, -1);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int here = pq.top().second;
            pq.pop();

            if (cost > dist[here]) continue;

            for (int there = 0; there < SIZE; ++there)
            {
                if (graph[here][there] == INF) continue;

                int nextDist = cost + graph[here][there];
                if (nextDist < dist[there])
                {
                    dist[there] = nextDist;
                    prev[there] = here;
                    pq.emplace(nextDist, there);
                }
            }
        }
    }

    void PrintPaths(int start)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            cout << "노드 " << start + 1 << " → 노드 " << i + 1 << " 최단 거리: ";
            if (dist[i] == INF)
            {
                cout << "도달 불가\n";
                continue;
            }
            cout << dist[i] << ", 경로: ";

            stack<int> path;
            for (int v = i; v != -1; v = prev[v])
                path.push(v);

            while (!path.empty())
            {
                cout << path.top() + 1;
                path.pop();
                if (!path.empty()) cout << " → ";
            }
            cout << "\n";
        }
    }

    const int& Find(int target)
    {
        return dist[target];
    }
};

int main()
{
    Dijkstra d;
    int start = 0; // index 0 = 노드 1
    d.Update(start);
    d.PrintPaths(start);

    // 특정 노드까지의 거리 확인 예시
    int target = 5; // 노드 6
    cout << "\n노드 1 → 노드 6 최단 거리: " << d.Find(target) << endl;

    return 0;
}
