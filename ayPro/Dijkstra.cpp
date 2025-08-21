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

    vector<int>    dist;      // ���������κ����� �ִ� �Ÿ�
    vector<int>    prev;      // ��� ������ ���� ���� ���
    vector<bool>   visited;   // �湮 ó��

public:
    Dijkstra()
        : dist(SIZE), prev(SIZE), visited(SIZE)
    {
    }

    // �̹湮 ��� �� dist�� �ּ��� ����� �ε����� ��ȯ
    // �� �̻� ��ȿ�� ��尡 ������ -1 ��ȯ
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
            // 1) �������� �湮�� ��带 Find�� ���Ѵ�
            int u = Find();
            if (u < 0)
                break;            // �� �̻� ����� ��尡 ������ ���� 

            visited[u] = true;

            // 2) u�� �������� �Ͽ� ���� ������ dist ����
            for (int v = 0; v < SIZE; ++v)
            {
                if (!visited[v] && graph[u][v] != INF)
                {
                    int nextD = dist[u] + graph[u][v];
                    if (nextD < dist[v])
                    {
                        dist[v] = nextD;
                        // ��¿��� ��� ������ ���� ���� ��� 
                        prev[v] = u;
                    }
                }
            }
        }
    }

    // ��� �� �ִ� �Ÿ��� ���
    void PrintPaths(int start) const
    {
        for (int i = 0; i < SIZE; ++i)
        {
            cout << "��� " << (start + 1)
                << " �� ��� " << (i + 1)
                << " �ִ� �Ÿ�: ";

            if (dist[i] == INF)
            {
                cout << "���� �Ұ�\n";
                continue;
            }

            cout << dist[i] << ", ���: ";
            stack<int> stk;
            for (int v = i; v != -1; v = prev[v])
                stk.push(v);

            while (!stk.empty())
            {
                cout << (stk.top() + 1);
                stk.pop();
                if (!stk.empty()) cout << " �� ";
            }
            cout << "\n";
        }
    }

    // Ư�� ���(target)�� �ִ� �Ÿ��� ��ȯ
    int GetDistance(int target) const
    {
        return dist[target];
    }
};

int main()
{
    Dijkstra solver;
    int start = 0;  // ��� 1 (index 0)

    solver.Update(start);
    solver.PrintPaths(start);

    cout << "\n��� 1 �� ��� 6 �ִ� �Ÿ�: "
        << solver.GetDistance(5) << "\n";

    return 0;
}
