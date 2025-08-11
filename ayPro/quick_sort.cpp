#include <iostream>
using namespace std;

// �迭�� �����ϴ� �Լ�
static int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // �ǹ��� ������ ��ҷ� ���� 
    // ���� ����� i�� -1, �� ���ĺ��ʹ� low index���� �ϳ� ����, ������ �ǹ������� ������ i++ �� �� ������ �̷������ �����̴�. 
    int i = low - 1;
    
    for (int j = low; j < high; j++) 
    {
        // j�� low���� high -1 ���� ��ȸ, �ǹ����� Ȯ���� �ʿ䰡 ����. 
        if (arr[j] < pivot) 
        {
            // ���� ����� i�� 0���� �ϳ��� ����, �� ���ĺ��ʹ� low������ �ϳ��� ����, ���⼭ i�� �ǹ������� ���� ������ ä��� index�� ����. 
            i++; 
            // �ǹ����� ���� ���� �������� �̵�, i == j �� ���� �ִµ� �� ���� swap�� �̷�� ���� �ʴ´�.  
            swap(arr[i], arr[j]);
        }
    }
    // �ݺ��� ���� �� i + 1 ��ġ�� �ǹ��� �־���  
    swap(arr[i + 1], arr[high]); 
    // �ǹ��� ���� ��ġ�� ��ȯ 
    return i + 1;
}

// ����Ʈ �Լ�
static void quickSort(int arr[], int low, int high)
{
    // �������� �������� ���� 
    if (low < high) 
    {
        // �ǹ� ��ġ�� index�� ��ȯ�ؼ� pi�� �Ҵ�, ���������� �ǹ��� �������� �ǹ������� ���� ���� ���ʿ� �ǹ������� ū ���� �����ʿ� ��ġ�ϰ� ��. 
        int pi = partition(arr, low, high); // ���� �ε��� 
        quickSort(arr, low, pi - 1);  // ���� �κ� ���� 
        quickSort(arr, pi + 1, high); // ������ �κ� ���� 
    }
}

// �迭 ��� �Լ�
static void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ���� �Լ�
int main() 
{
    int arr[] = { 10, 7, 8, 9, 1, 4, 5, 3, 2, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "���� �� �迭: ";
    printArray(arr, n); 

    quickSort(arr, 0, n - 1);

    cout << "���� �� �迭: ";
    printArray(arr, n);
    return 0;
}
