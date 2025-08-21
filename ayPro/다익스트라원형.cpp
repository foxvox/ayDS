 
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph, vector<int>& dist)
{
    int n = graph.size();
    dist.assign(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (cost > dist[here]) continue;

        for (auto& edge : graph[here]) {
            int there = edge.first;
            int nextDist = cost + edge.second;

            if (nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.emplace(nextDist, there);
            }
        }
    }
}

int main()
{
    int n = 5; // 노드 수
    vector<vector<pair<int, int>>> graph(n);

    // 간선 추가: graph[출발노드].emplace_back(도착노드, 가중치);
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(2, 3);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(3, 2);
    graph[2].emplace_back(1, 4);
    graph[2].emplace_back(3, 8);
    graph[2].emplace_back(4, 2);
    graph[3].emplace_back(4, 7);
    graph[4].emplace_back(3, 9);

    vector<int> dist;
    dijkstra(0, graph, dist);

    for (int i = 0; i < n; ++i) {
        cout << "0번 노드에서 " << i << "번 노드까지의 최단 거리: ";
        if (dist[i] == INF) cout << "도달 불가\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
