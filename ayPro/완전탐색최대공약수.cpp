#include <iostream> 
using namespace std;

int main()
{
#pragma region 유클리드호제법 
	// 2개의 자연수 또는 정식의 최대 공약수를 구하는 방식으로 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘 
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

	cout << "최대공약수: " << gcd << endl;
#pragma endregion
}