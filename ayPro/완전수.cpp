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
		cout << num << "은 완전수입니다" << endl;
	}
	else
	{
		cout << num << "은 완전수가 아닙니다" << endl;
	}
}