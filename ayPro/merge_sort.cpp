#include <iostream>
using namespace std;

static void merge(int arr[], int left, int mid, int right) 
{
    // n1 왼쪽 부분 배열의 크기 : left 부터 미드까지 요소의 개수 
    int n1 = mid - left + 1; 
    // n2 오른쪽 부분 배열의 크기 : 미드 + 1 부터 끝까지 요소의 개수 
    int n2 = right - mid;

    // 동적 배열 할당
    int* L = new int[n1];
    int* R = new int[n2];

    // 왼쪽부터 미드까지를 L 배열에 할당 
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    // 미드 + 1 부터 끝까지를 R 배열에 할당 
    for (int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 

    // 이 부분에서 실질적인 정렬이 이루어진다. 
    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) 
    {
        // 왼쪽와 오른쪽 부분 배열의 처음 요소끼리 비교해서 더 작거나 같은 요소를 arr 배열에 넣고 더 작거나 같은 배열의 인덱스와 arr 배열의 인덱스를 하나 추가 
        // 더 큰 요소가 있었던 배열의 인덱스는 증가하지 않았으므로 그 요소와 인덱스 하나 증가한 후의 요소가 비교되게 된다. 
        if (L[i] <= R[j])
            arr[k++] = L[i++]; 
        else
            arr[k++] = R[j++]; 
    }

    // L 또는 R 중 하나는 아직 요소가 남아 있을 수 있으므로, 그걸 복사하는 추가 루프가 뒤에 붙습니다. 
    while (i < n1) 
        arr[k++] = L[i++]; 

    while (j < n2)
        arr[k++] = R[j++]; 

    // 메모리 해제
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

    cout << "정렬 전 배열: "; 
    printArray(arr, arrSize); 

    mergeSort(arr, 0, arrSize - 1); 

    cout << "정렬 후 배열: ";
    printArray(arr, arrSize);

    return 0;
}
