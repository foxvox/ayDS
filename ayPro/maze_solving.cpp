#include <iostream>
#include <vector>
#include <string> // string(depth * 2, ' ') ����� ���� �ʿ�
using namespace std;

constexpr int N = 4;

// 2D ���� ����ü ����
struct Vector2
{
    int x, y;  // x: ��(column), y: ��(row)
    Vector2(int x = 0, int y = 0) : x(x), y(y) {}
};

// �̷� ���� (1: ��, 0: ��) 
int maze[N][N] =
{
    {1, 0, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 1}
};

bool visited[N][N]{};
vector<Vector2> path{};

// �����ϼ��� ó���ϸ� ������ �ٷ� ã�ư�, ���ϵ����� ó���ϸ� ��Ʈ��ŷ ������ ��ġ�� ��. 
Vector2 directions[] =
{
    Vector2(0,  1),  // �� (down) 
    Vector2(1,  0),  // �� (right)
    Vector2(0, -1),  // �� (up)              
    Vector2(-1, 0)   // �� (left)
};

bool dfs(Vector2 current, Vector2 endPos, int depth = 0)
{
    int x = current.x;
    int y = current.y;

    cout << string(depth * 2, ' ') << "Enter dfs index Pos: " << y << "," << x << "\n";

    // ���� ��� üũ
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;

    // ���̰ų� �̹� �湮�� ������ üũ  
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
        // �ٷ� ���⼭ ���ȣ���� ��� �߻���
        if (dfs(next, endPos, depth + 1))
        {
			// ���� �������� ������ ��� �� ������� ������ 
            return true; 
        }
    }

	// ��Ʈ��ŷ : ���� ��� ������ �ƴ϶� ���� ���ٸ� ���̰� �� ������ ��Ʈ��ŷ�� �߻�, ��Ʈ��ŷ �߻��ϸ� path���� ���� ��ġ ����       
    cout << string(depth * 2, ' ') << "Backtrack from Pos: " << y << "," << x << "\n"; 
    path.pop_back();    

    return false;
}

void printMazeWithPath()
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
    for (int row = 0; row < N; ++row) 
    {
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
    Vector2 startPos(0, 0);
    Vector2 endPos(3, 3);

    if (dfs(startPos, endPos, 0)) 
    {
        cout << "\n���� ������ ���:\n";
        printMazeWithPath();
    }
    else 
    {
        cout << "�̵��� �� �����ϴ�.\n";
    }

    return 0;
} 