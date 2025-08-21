#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

#define SIZE 6
const int INF = numeric_limits<int>::max();

/// 경로 추적용으로 노드 번호와 거리를 담는 구조체
struct Vector2 {
    int node;      // 노드 번호 (0-based)
    int dist;      // 시작점으로부터의 누적 거리

    Vector2(int n, int d)
        : node(n), dist(d) {
    }
};

// 최소힙을 만들기 위한 비교 함수
struct Compare {
    bool operator()(const Vector2& a, const Vector2& b) const {
        return a.dist > b.dist;  // 더 작은 dist를 우선
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

    vector<int> dist;   // 최단 거리 테이블
    vector<int> prev;   // 경로 복원을 위한 이전 노드 테이블

public:
    Dijkstra() {
        dist.resize(SIZE);
        prev.resize(SIZE);
    }

    /// 다익스트라 수행 (priority_queue 버전)
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

            // 인접한 모든 노드 검사
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

    /// 계산된 최단 거리와 경로를 출력
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

    /// 특정 목표 노드까지의 최단 거리만 반환
    int  Find(int target) const {
        return dist[target];
    }
};

int main() {
    Dijkstra solver;

    int start = 0;  // 인덱스 0 = 노드 1
    solver.UpdateWithPQ(start);
    solver.PrintPaths(start);

    // 노드 1 → 노드 6 최단 거리 확인
    cout << "\n노드 1 → 노드 6 최단 거리: "
        << solver.Find(5) << "\n";

    return 0;
}
