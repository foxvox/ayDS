#include <iostream>
using namespace std;

static int GCDFunc(int x, int y)
{
    int modNum = INT_MAX;

    int temp = y;
    modNum = x % y;

    if (modNum == 0)
    {
        return y;
    }

    x = temp;
    y = modNum;

    GCDFunc(x, y);
}

int main()
{
    int result = 0, leftNum = 3, rightNum = 5;
    result = GCDFunc(leftNum, rightNum);
    cout << "최대공약수: " << result << endl;

    return 0;
}
