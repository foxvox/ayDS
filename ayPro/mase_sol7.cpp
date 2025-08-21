#include <iostream>
#include <vector>
using namespace std;

const int N = 4;
int maze[N][N] =
{
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 0, 0, 0},
    {1, 1, 1, 0}
};

bool visited[N][N];
vector<pair<int, int>> path;

// 방향: 남, 북, 동, 서 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

static bool dfs(int x, int y, int endX, int endY)
{
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    if (maze[x][y] == 1 || visited[x][y]) return false;

    visited[x][y] = true;
    path.push_back({ x, y });

    if (x == endX && y == endY) return true;

    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (dfs(nx, ny, endX, endY)) return true;
    }

    path.pop_back(); // 백트래킹
    return false;
}

static void printMazeWithPath()
{
    char display[N][N]{};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            display[i][j] = (maze[i][j] == 1 ? '#' : '.');

    for (auto& p : path)
    {
        int x = p.first;
        int y = p.second;
        display[x][y] = '*';
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << display[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    int startX = 0, startY = 0;
    int endX = 3, endY = 3;

    if (dfs(startX, startY, endX, endY))
    {
        cout << "도달 가능한 경로:\n";
        printMazeWithPath();
    }
    else
    {
        cout << "이동할 수 없습니다.\n";
    }

    return 0;
}
