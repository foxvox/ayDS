#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

const int INF = numeric_limits<int>::max();

class Dijkstra
{
public:
    int n = 7; // ��� ��
    vector<vector<pair<int, int>>> graph;

    Dijkstra() : graph(n)
    {
        graph[1].emplace_back(2, 2);
        graph[1].emplace_back(3, 5);
        graph[1].emplace_back(4, 1);
        graph[2].emplace_back(4, 2);
        graph[2].emplace_back(3, 3);
        graph[3].emplace_back(4, 3);
        graph[3].emplace_back(5, 1);
        graph[3].emplace_back(6, 5);
        graph[4].emplace_back(5, 1);
        graph[5].emplace_back(6, 2);
    }

    void run(int start)
    {
        vector<int> dist(n, INF);
        vector<int> prev(n, -1); // ��� ������
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int here = pq.top().second;
            pq.pop();

            if (cost > dist[here]) continue;

            for (auto& edge : graph[here])
            {
                int there = edge.first;
                int nextDist = cost + edge.second;

                if (nextDist < dist[there])
                {
                    dist[there] = nextDist;
                    prev[there] = here; // ��� ����
                    pq.emplace(nextDist, there);
                }
            }
        }

        // ��� ���
        for (int i = 1; i < n; ++i)
        {
            cout << start << "�� ��� �� " << i << "�� ��� �ִ� �Ÿ�: ";
            if (dist[i] == INF)
            {
                cout << "���� �Ұ�\n";
                continue;
            }

            cout << dist[i] << ", ���: ";

            // ��� ������
            stack<int> path;
            for (int v = i; v != -1; v = prev[v])
                path.push(v);

            while (!path.empty())
            {
                cout << path.top();
                path.pop();
                if (!path.empty()) cout << " �� ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Dijkstra d;
    d.run(1); // 1�� ��忡�� ����
    return 0;
}
