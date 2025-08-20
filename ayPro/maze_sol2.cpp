#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 4;

// 2D ���� ����ü ����
struct Vector2
{
    int x, y;  // x: ��(column), y: ��(row)
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

// ����: ��, ��, ��, �� (dx, dy)
Vector2 directions[] =
{
    Vector2(0,  1),  // �� (down)
    Vector2(0, -1),  // �� (up)
    Vector2(1,  0),  // �� (right)
    Vector2(-1, 0)   // �� (left)
};

static bool dfs(Vector2 current, Vector2 endPos)
{
    int x = current.x;
    int y = current.y;

    // ���� ��� üũ
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;

    // ���̰ų� �̹� �湮�� ���̸� ����
    if (maze[y][x] == 0 || visited[y][x])
        return false;

    // �湮 ó�� & ��ο� �߰�
    visited[y][x] = true;
    path.push_back(current);

    // ������ ���������� ����
    if (x == endPos.x && y == endPos.y)
        return true;

    // �� ���� Ž��
    for (auto& dir : directions)
    {
        Vector2 next(x + dir.x, y + dir.y);
        if (dfs(next, endPos))
            return true;
    }

    // ��Ʈ��ŷ
    path.pop_back();
    return false;
}

static void printMazeWithPath()
{
    char display[N][N]{};

    // �⺻ �̷� ǥ��(. �� ĭ, # ��)
    for (int row = 0; row < N; ++row)
        for (int col = 0; col < N; ++col)
            display[row][col] = (maze[row][col] == 0 ? '#' : '.');

    // ��� ǥ��(*)
    for (auto& p : path)
        display[p.y][p.x] = '*';

    // �̷� ���
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col)
            cout << display[row][col] << ' ';
        cout << '\n';
    }

    // ��� ��ǥ ���
    cout << "\n��� �ε��� ��ǥ:\n";
    for (auto& p : path)
        cout << "(" << p.x << ", " << p.y << ") ";
    cout << '\n';
}

int main()
{
    // ���� ��ġ�� ���� ��ġ ���ͷ� ����
    Vector2 startPos(0, 0);
    Vector2 endPos(3, 3);

    if (dfs(startPos, endPos)) {
        cout << "���� ������ ���:\n";
        printMazeWithPath();
    }
    else {
        cout << "�̵��� �� �����ϴ�.\n";
    }

    return 0;
}