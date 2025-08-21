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

    /// ���� Ž�� ��� ���ͽ�Ʈ�� 
    void Update(int start) 
    {
        vector<bool> visited(SIZE, false);
        fill(dist.begin(), dist.end(), INF);
        fill(prev.begin(), prev.end(), -1);
        dist[start] = 0;

        for (int iter = 0; iter < SIZE; ++iter) 
        {
            // 1) ���� �湮���� ���� ��� �� dist�� �ּ��� ��带 ã�´�
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
                break;  // �� �̻� ���� ������ ��� ����

            visited[u] = true;

            // 2) ���õ� u�� ���� �ٸ� ����� �Ÿ� ����
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

    int Find(int target) const 
    {
        return dist[target];
    }
};

int main() {
    Dijkstra solver;
    int start = 0;  // ��� 1 (index 0)
    solver.Update(start);
    solver.PrintPaths(start);

    cout << "\n��� 1 �� ��� 6 �ִ� �Ÿ�: "
        << solver.Find(5) << "\n";

    return 0;
}
