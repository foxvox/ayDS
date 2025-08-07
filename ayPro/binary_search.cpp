#include <iostream>
#include <vector>
using namespace std;

// �̺�Ž�� �Լ� ����
static int find(const vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        // pivot ��ġ�� ����Ѵ�. 
        int pivot = left + (right - left) / 2;

        if (vec[pivot] == target)
        {
            return pivot; // ã���� ��� �ε��� ��ȯ
        }
        else if (vec[pivot] < target)
        {
            left = pivot + 1; // ������ ������ �̵� 
        }
        else 
        {
            right = pivot - 1; // ���� ������ �̵� 
        }
    }

    return -1; // ã�� ���� ��� 
}

int main()
{
    vector<int> sortedVec = { 1, 3, 5, 7, 9, 11, 13, 15 , 20, 23, 25}; 
    int target = 23;

    int index = find(sortedVec, target); 

    if (index != -1)
    {
        cout << "�� " << target << " ��(��) �ε��� " << index << " �� �ֽ��ϴ�." << endl;
    }
    else 
    {
        cout << "�� " << target << " ��(��) ã�� �� �����ϴ�." << endl; 
    }

    return 0;
}
