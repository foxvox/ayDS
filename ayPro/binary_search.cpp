#include <iostream>
#include <vector>
using namespace std;

// 이분탐색 함수 정의
static int find(const vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        // pivot 위치를 계산한다. 
        int pivot = left + (right - left) / 2;

        if (vec[pivot] == target)
        {
            return pivot; // 찾았을 경우 인덱스 반환
        }
        else if (vec[pivot] < target)
        {
            left = pivot + 1; // 오른쪽 범위로 이동 
        }
        else 
        {
            right = pivot - 1; // 왼쪽 범위로 이동 
        }
    }

    return -1; // 찾지 못한 경우 
}

int main()
{
    vector<int> sortedVec = { 1, 3, 5, 7, 9, 11, 13, 15 , 20, 23, 25}; 
    int target = 23;

    int index = find(sortedVec, target); 

    if (index != -1)
    {
        cout << "값 " << target << " 은(는) 인덱스 " << index << " 에 있습니다." << endl;
    }
    else 
    {
        cout << "값 " << target << " 을(를) 찾을 수 없습니다." << endl; 
    }

    return 0;
}
