#include <iostream>
using namespace std;

static int fibo(int n, int* _pArr)
{
    // 기본값 세팅
    _pArr[0] = 0;
    if (n == 0) return _pArr[0];

    _pArr[1] = 1;
    if (n == 1) return _pArr[1];

    // n까지 계산 
    for (int i = 2; i <= n; i++)
    {
        _pArr[i] = _pArr[i - 1] + _pArr[i - 2];
    }

    return _pArr[n];
}

int main()
{
    int n = 40;
    int* pArr = new int[n];

    int result = fibo(n, pArr);

    cout << n << "번째 값: " << result << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "pArr[" << i << "]: " << pArr[i] << endl;
    }

    return 0;
}
