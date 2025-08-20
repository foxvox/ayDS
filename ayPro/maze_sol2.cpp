#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 4;

// 2D 벡터 구조체 정의
struct Vector2
{
    int x, y;  // x: 열(column), y: 행(row)
    Vector2(int x = 0, int y = 0) : x(x), y(y) {}
};

int maze[N][N] =
{
    {1, 0, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 1}
};

bool visited[N][N];
vector<Vector2> path;

// 방향: 남, 북, 동, 서 (dx, dy)
Vector2 directions[] =
{
    Vector2(0,  1),  // 남 (down)
    Vector2(0, -1),  // 북 (up)
    Vector2(1,  0),  // 동 (right)
    Vector2(-1, 0)   // 서 (left)
};

static bool dfs(Vector2 current, Vector2 endPos)
{
    int x = current.x;
    int y = current.y;

    // 범위 벗어남 체크
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;

    // 벽이거나 이미 방문한 곳이면 실패
    if (maze[y][x] == 0 || visited[y][x])
        return false;

    // 방문 처리 & 경로에 추가
    visited[y][x] = true;
    path.push_back(current);

    // 목적지 도달했으면 성공
    if (x == endPos.x && y == endPos.y)
        return true;

    // 네 방향 탐색
    for (auto& dir : directions)
    {
        Vector2 next(x + dir.x, y + dir.y);
        if (dfs(next, endPos))
            return true;
    }

    // 백트래킹
    path.pop_back();
    return false;
}

static void printMazeWithPath()
{
    char display[N][N]{};

    // 기본 미로 표시(. 빈 칸, # 벽)
    for (int row = 0; row < N; ++row)
        for (int col = 0; col < N; ++col)
            display[row][col] = (maze[row][col] == 0 ? '#' : '.');

    // 경로 표시(*)
    for (auto& p : path)
        display[p.y][p.x] = '*';

    // 미로 출력
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col)
            cout << display[row][col] << ' ';
        cout << '\n';
    }

    // 경로 좌표 출력
    cout << "\n경로 인덱스 좌표:\n";
    for (auto& p : path)
        cout << "(" << p.x << ", " << p.y << ") ";
    cout << '\n';
}

int main()
{
    // 시작 위치와 종료 위치 벡터로 정의
    Vector2 startPos(0, 0);
    Vector2 endPos(3, 3);

    if (dfs(startPos, endPos)) {
        cout << "도달 가능한 경로:\n";
        printMazeWithPath();
    }
    else {
        cout << "이동할 수 없습니다.\n";
    }

    return 0;
}