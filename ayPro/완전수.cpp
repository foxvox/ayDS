#include <iostream> 
#include <vector> 
using namespace std;

int main()
{
	int num = 28;
	vector<int> div;
	bool isTrue = false;
	int result = 0;

	for (int i = 1; i <= num / 2; i++) 
	{ 
		if (num % i == 0)
		{
			div.push_back(i);
		}
	}

	for (int& e : div)
	{
		result += e; 
	}

	if (result == num) 
	{
		isTrue = true; 
	}

	if (isTrue) 
	{
		cout << num << "�� �������Դϴ�" << endl;
	}
	else
	{
		cout << num << "�� �������� �ƴմϴ�" << endl;
	}
}