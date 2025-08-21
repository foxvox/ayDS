#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

#define SIZE 6
const int INF = numeric_limits<int>::max();

/// ��� ���������� ��� ��ȣ�� �Ÿ��� ��� ����ü
struct Vector2 {
    int node;      // ��� ��ȣ (0-based)
    int dist;      // ���������κ����� ���� �Ÿ�

    Vector2(int n, int d)
        : node(n), dist(d) {
    }
};

// �ּ����� ����� ���� �� �Լ�
struct Compare {
    bool operator()(const Vector2& a, const Vector2& b) const {
        return a.dist > b.dist;  // �� ���� dist�� �켱
    }
};

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

    vector<int> dist;   // �ִ� �Ÿ� ���̺�
    vector<int> prev;   // ��� ������ ���� ���� ��� ���̺�

public:
    Dijkstra() {
        dist.resize(SIZE);
        prev.resize(SIZE);
    }

    /// ���ͽ�Ʈ�� ���� (priority_queue ����)
    void UpdateWithPQ(int start) {
        fill(dist.begin(), dist.end(), INF);
        fill(prev.begin(), prev.end(), -1);
        dist[start] = 0;

        priority_queue<Vector2, vector<Vector2>, Compare> pq;
        pq.emplace(start, 0);

        while (!pq.empty()) {
            Vector2 top = pq.top(); pq.pop();
            int here = top.node;
            int cost = top.dist;

            if (cost > dist[here])
                continue;

            // ������ ��� ��� �˻�
            for (int there = 0; there < SIZE; ++there) {
                if (graph[here][there] == INF)
                    continue;

                int nextDist = cost + graph[here][there];
                if (nextDist < dist[there]) {
                    dist[there] = nextDist;
                    prev[there] = here;
                    pq.emplace(there, nextDist);
                }
            }
        }
    }

    /// ���� �ִ� �Ÿ��� ��θ� ���
    void PrintPaths(int start) const {
        for (int i = 0; i < SIZE; ++i) {
            cout << "��� " << (start + 1)
                << " �� ��� " << (i + 1)
                << " �ִ� �Ÿ�: ";

            if (dist[i] == INF) {
                cout << "���� �Ұ�\n";
                continue;
            }

            cout << dist[i] << ", ���: ";
            stack<int> stk;
            for (int v = i; v != -1; v = prev[v])
                stk.push(v);

            while (!stk.empty()) {
                cout << (stk.top() + 1);
                stk.pop();
                if (!stk.empty()) cout << " �� ";
            }
            cout << "\n";
        }
    }

    /// Ư�� ��ǥ �������� �ִ� �Ÿ��� ��ȯ
    int  Find(int target) const {
        return dist[target];
    }
};

int main() {
    Dijkstra solver;

    int start = 0;  // �ε��� 0 = ��� 1
    solver.UpdateWithPQ(start);
    solver.PrintPaths(start);

    // ��� 1 �� ��� 6 �ִ� �Ÿ� Ȯ��
    cout << "\n��� 1 �� ��� 6 �ִ� �Ÿ�: "
        << solver.Find(5) << "\n";

    return 0;
}
