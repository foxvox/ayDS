#include <iostream> 

using namespace std;

int main()
{
#pragma region ���÷��̽����� 

#pragma region ��ǰ���� 
    int arr[] = { 5, 7, 3, 1, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // ��ǰ ���� �˰���
    for (int i = 0; i < n - 1; ++i) // index 0 ~ 3���� �ٲ�� ��. 
    {
        // i�� 0�� ��, 0 ~ 3���� ��ȸ => ��ȸ �� 4index�� �ִ밪 ��. i�� 1�� �� 0 ~ 2���� ��ȸ => ��ȸ �� 3index�� 2��° ū ���� ��. 
        for (int j = 0; j < n - i - 1; ++j)
        { 
            if (arr[j] > arr[j + 1]) 
            { 
                // swap 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            }
        }
    }

    // ��� ���
    cout << "�������� ���� ���: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#pragma endregion

#pragma endregion

}