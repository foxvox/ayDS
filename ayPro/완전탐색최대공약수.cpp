#include <iostream> 
using namespace std;

int main()
{
#pragma region ��Ŭ����ȣ���� 
	// 2���� �ڿ��� �Ǵ� ������ �ִ� ������� ���ϴ� ������� �� ���� ���� ���� ���� ����� ���ϴ� ���� ���� �˰��� 
	int gcd = 0;

	int leftNum = 16, rightNum = 24;

	int minNum = leftNum < rightNum ? leftNum : rightNum;

	for (int i = 1; i <= minNum; i++)
	{
		if (leftNum % i == 0 && rightNum % i == 0)
		{
			gcd = i;
		}
	}

	cout << "�ִ�����: " << gcd << endl;
#pragma endregion
}