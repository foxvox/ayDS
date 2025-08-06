#include <iostream> 

using namespace std;

int main()
{
#pragma region 완전탐색알고리즘 
	// 가능한 모든 경우의 수를 탐색하면서 결과를 찾아내는 알고리즘 
	int password[3]{ 4, 8, 7 };
	int findNum[3]{};

	for (int i = 0; i < 10; i++)
	{
		if (password[0] == i)
		{
			findNum[0] = i;
		}

		if (password[1] == i)
		{
			findNum[1] = i;
		}

		if (password[2] == i)
		{
			findNum[2] = i;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << findNum[i];
	}
#pragma endregion

}