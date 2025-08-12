#include <iostream>
using namespace std;

static void merge(int arr[], int left, int mid, int right) 
{
    // n1 ���� �κ� �迭�� ũ�� : left ���� �̵���� ����� ���� 
    int n1 = mid - left + 1; 
    // n2 ������ �κ� �迭�� ũ�� : �̵� + 1 ���� ������ ����� ���� 
    int n2 = right - mid;

    // ���� �迭 �Ҵ�
    int* L = new int[n1];
    int* R = new int[n2];

    // ���ʺ��� �̵������ L �迭�� �Ҵ� 
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    // �̵� + 1 ���� �������� R �迭�� �Ҵ� 
    for (int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 

    // �� �κп��� �������� ������ �̷������. 
    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) 
    {
        // ���ʿ� ������ �κ� �迭�� ó�� ��ҳ��� ���ؼ� �� �۰ų� ���� ��Ҹ� arr �迭�� �ְ� �� �۰ų� ���� �迭�� �ε����� arr �迭�� �ε����� �ϳ� �߰� 
        // �� ū ��Ұ� �־��� �迭�� �ε����� �������� �ʾ����Ƿ� �� ��ҿ� �ε��� �ϳ� ������ ���� ��Ұ� �񱳵ǰ� �ȴ�. 
        if (L[i] <= R[j])
            arr[k++] = L[i++]; 
        else
            arr[k++] = R[j++]; 
    }

    // L �Ǵ� R �� �ϳ��� ���� ��Ұ� ���� ���� �� �����Ƿ�, �װ� �����ϴ� �߰� ������ �ڿ� �ٽ��ϴ�. 
    while (i < n1) 
        arr[k++] = L[i++]; 

    while (j < n2)
        arr[k++] = R[j++]; 

    // �޸� ����
    delete[] L; 
    delete[] R; 
}

static void mergeSort(int arr[], int left, int right)  
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right); 
    }
}

static void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() 
{
    int arr[] = { 12, 11, 13, 5, 6, 7, 8, 4, 3, 9, 15, 18, 17, 10 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "���� �� �迭: "; 
    printArray(arr, arrSize); 

    mergeSort(arr, 0, arrSize - 1); 

    cout << "���� �� �迭: ";
    printArray(arr, arrSize);

    return 0;
}
