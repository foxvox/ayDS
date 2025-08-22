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

// 남동북서로 하면 빠르게 경로를 찾고 남북동서로 하면 백트래킹이 이루어짐 
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

	cout << string(depth * 2, ' ') << "depth: " << depth << "  " << "Current Position => 행 inex : " << y << ", 열 index : " << x << "\n";

	// index가 mazs 범위를 벗어나면 return false 
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;

	// index 위치가 벽이거나 방문한 곳이면 return false 
	if (maze[y][x] == 0 || visited[y][x] == true)
		return false;

	// 범위 안에 있고, 벽이 아니고 방문한 곳도 아니라면, 경로에 추가하고 방문한 곳으로 등록한다.  
	path.push_back(currPos);
	visited[y][x] = true;

	// 현재 위치가 도착점과 같으면 return true 
	if (x == destPos.x && y == destPos.y)
		return true;

	Vector2 nextPos(0, 0);
	for (Vector2 dir : direction)
	{
		nextPos.x = currPos.x + dir.x;
		nextPos.y = currPos.y + dir.y;

		// 여기서 도착점에 도착할 때까지 재귀호출이 발생한다. 
		if (dfs(nextPos, destPos, depth + 1))
		{
			return true;
		}
	}

	// 백트래킹 : 로직이 여기에 이른 것은 막다른 곳에 다다랐다는 뜻이다. 백트래킹 발생하면 path에서 현재 위치 제거       
	cout << string(depth * 2, ' ') << "depth: " << depth << "  " << "Backtracking from Position => 행 inex : " << y << ", 열 index : " << x << "\n";
	path.pop_back();

	return false;
}

void PrintMazeWithPath()
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
	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
			cout << display[row][col] << ' ';
		cout << '\n';
	}

	// 경로 좌표 출력
	cout << "\n경로 인덱스 좌표:\n";
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
		cout << "도착하지 못했습니다." << endl;
	}

	return 0;
}

