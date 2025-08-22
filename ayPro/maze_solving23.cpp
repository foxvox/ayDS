#include <iostream>
#include <vector>
#include <string> 
using namespace std;
constexpr int N = 4;

struct Vector2
{
	int x = 0;
	int y = 0;
	Vector2(int _x, int _y) : x(_x), y(_y)
	{
	}
};

int maze[N][N] =
{
	{1, 0, 1, 1},
	{1, 0, 1, 0},
	{1, 1, 1, 1},
	{0, 0, 0, 1}
};

// �����ϼ��� �ϸ� ������ ��θ� ã�� ���ϵ����� �ϸ� ��Ʈ��ŷ�� �̷���� 
vector<Vector2> direction =
{
	Vector2(0, 1),
	Vector2(0, -1),
	Vector2(1, 0),
	Vector2(-1, 0)
};

vector<Vector2> path{};
bool			visited[N][N]{ false };

bool dfs(Vector2 currPos, Vector2 destPos, int depth = 0)
{
	int x = currPos.x;
	int y = currPos.y;

	cout << string(depth * 2, ' ') << "depth: " << depth << "  " << "Current Position => �� inex : " << y << ", �� index : " << x << "\n";

	// index�� mazs ������ ����� return false 
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;

	// index ��ġ�� ���̰ų� �湮�� ���̸� return false 
	if (maze[y][x] == 0 || visited[y][x] == true)
		return false;

	// ���� �ȿ� �ְ�, ���� �ƴϰ� �湮�� ���� �ƴ϶��, ��ο� �߰��ϰ� �湮�� ������ ����Ѵ�.  
	path.push_back(currPos);
	visited[y][x] = true;

	// ���� ��ġ�� �������� ������ return true 
	if (x == destPos.x && y == destPos.y)
		return true;

	Vector2 nextPos(0, 0);
	for (Vector2 dir : direction)
	{
		nextPos.x = currPos.x + dir.x;
		nextPos.y = currPos.y + dir.y;

		// ���⼭ �������� ������ ������ ���ȣ���� �߻��Ѵ�. 
		if (dfs(nextPos, destPos, depth + 1))
		{
			return true;
		}
	}

	// ��Ʈ��ŷ : ������ ���⿡ �̸� ���� ���ٸ� ���� �ٴٶ��ٴ� ���̴�. ��Ʈ��ŷ �߻��ϸ� path���� ���� ��ġ ����       
	cout << string(depth * 2, ' ') << "depth: " << depth << "  " << "Backtracking from Position => �� inex : " << y << ", �� index : " << x << "\n";
	path.pop_back();

	return false;
}

void PrintMazeWithPath()
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
	for (Vector2& p : path)
		cout << "(" << p.x << ", " << p.y << ") ";
	cout << '\n';
}

int main()
{
	Vector2 startPos(0, 0);
	Vector2 destPos(3, 3);

	if (dfs(startPos, destPos, 0))
	{
		PrintMazeWithPath();
	}
	else
	{
		cout << "�������� ���߽��ϴ�." << endl;
	}

	return 0;
}

