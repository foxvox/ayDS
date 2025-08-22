#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Vector2 {
    int x = 0;
    int y = 0;
    Vector2(int _x, int _y) : x(_x), y(_y) {}
};

vector<Vector2> direction = {
    Vector2(0, 1),   // ��
    Vector2(0, -1),  // ��
    Vector2(1, 0),   // ��
    Vector2(-1, 0)   // ��
};

vector<vector<int>>     maze;
vector<vector<bool>>    visited;
vector<Vector2>         path;
int                     ROW = 0, COL = 0;

static bool dfs(Vector2 currPos, Vector2 destPos, int depth = 0)
{
    int x = currPos.x;
    int y = currPos.y;

    cout << string(depth * 2, ' ') << "depth: " << depth
        << "  Current Position => �� index: " << y << ", �� index: " << x << "\n";

    if (x < 0 || x >= COL || y < 0 || y >= ROW) 
        return false;

    if (maze[y][x] == 0 || visited[y][x])
        return false;

    path.push_back(currPos);
    visited[y][x] = true;

    if (x == destPos.x && y == destPos.y)
        return true;

    for (const Vector2& dir : direction)
    {
        Vector2 nextPos(currPos.x + dir.x, currPos.y + dir.y);
        if (dfs(nextPos, destPos, depth + 1))
            return true;
    }

    cout << string(depth * 2, ' ') << "depth: " << depth
        << "  Backtracking from Position => �� index: " << y << ", �� index: " << x << "\n";
    path.pop_back();
    return false;
}

static void PrintMazeWithPath()
{
    vector<vector<char>> display(ROW, vector<char>(COL)); 

    for (int row = 0; row < ROW; ++row)
        for (int col = 0; col < COL; ++col)
            display[row][col] = (maze[row][col] == 0 ? '#' : '.');

    for (const Vector2& p : path)
        display[p.y][p.x] = '*';

    for (int row = 0; row < ROW; ++row)
    {
        for (int col = 0; col < COL; ++col)
            cout << display[row][col] << ' ';
        cout << '\n';
    }

    cout << "\n��� �ε��� ��ǥ:\n";
    for (const Vector2& p : path)
        cout << "(" << p.x << ", " << p.y << ") "; 
    cout << '\n';
}

int main()
{
    cout << "�̷� ũ�⸦ �Է��ϼ��� (��: 4 4): ";
    cin >> ROW >> COL;

    maze.resize(ROW, vector<int>(COL));
    visited.resize(ROW, vector<bool>(COL, false)); 

    cout << "�̷� �����͸� �Է��ϼ��� (" << ROW << "�� " << COL << "��):\n";
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            cin >> maze[i][j];

    Vector2 startPos(0, 0);
    Vector2 destPos(COL - 1, ROW - 1);

    cout << endl; 

    if (dfs(startPos, destPos, 0))
        PrintMazeWithPath();
    else 
        cout << "�������� ���߽��ϴ�.\n";

    return 0;
}
