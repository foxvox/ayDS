 
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
    int n = 5; // ��� ��
    vector<vector<pair<int, int>>> graph(n);

    // ���� �߰�: graph[��߳��].emplace_back(�������, ����ġ);
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
        cout << "0�� ��忡�� " << i << "�� �������� �ִ� �Ÿ�: ";
        if (dist[i] == INF) cout << "���� �Ұ�\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
