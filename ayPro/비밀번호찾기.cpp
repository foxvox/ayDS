#include <iostream> 

using namespace std;

int main()
{
#pragma region ����Ž���˰��� 
	// ������ ��� ����� ���� Ž���ϸ鼭 ����� ã�Ƴ��� �˰��� 
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