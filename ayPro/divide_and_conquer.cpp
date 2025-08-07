#include <iostream> 
using namespace std;

int getMax(int list[], int left, int right)
{
	if (left == right)
	{
		return list[left];
	}
	else
	{
		int leftMax = getMax(list, left, (left + right) / 2);
		int rightMax = getMax(list, (left + right) / 2 + 1, right);

		if (leftMax < rightMax)
		{
			return rightMax;
		}
		else
		{
			return leftMax;
		}
	}
}

int main()
{
#pragma region �������� 
	// �־��� 2�� �̻��� �κ����� ������ ���� �� �� �κ� ������ ���� ���� ��� ȣ���� �̿��Ͽ� ����� ����, 
	// �� �����κ��� ��ü ������ ���� ����ϴ� �˰����Դϴ�. 
	// ����(Divide)	: �־��� ������ �� �� Ȥ�� �� �̻��� �������� ������. 
	// ����(Conquer)	: �������� ������ ��������� �ذ��ؼ� �������� ������ �� �̻� ���� �ʿ䰡 ���� ������ ��� �����Ѵ�. 
	// ����(Combine)	: ����� �ذ��� �������� �����ؼ� ���� ������ �ش��� �����մϴ�. 

	int list[]{ 20, 15, 74, 15, 99, 1, 30, 70 };

	int size = sizeof(list) / sizeof(list[0]);

	cout << getMax(list, 0, size - 1) << endl;
#pragma endregion 
}