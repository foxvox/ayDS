#include <iostream>
using namespace std;

// 배열을 분할하는 함수
static int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // 피벗을 마지막 요소로 설정 
    // 최초 실행시 i는 -1, 그 이후부터는 low index에서 하나 뺀다, 이유는 피벗값보다 작으면 i++ 한 후 스왑이 이루어지기 때문이다. 
    int i = low - 1;
    
    for (int j = low; j < high; j++) 
    {
        // j는 low부터 high -1 까지 순회, 피벗값은 확인할 필요가 없음. 
        if (arr[j] < pivot) 
        {
            // 최초 실행시 i는 0부터 하나씩 증가, 그 이후부터는 low값부터 하나씩 증가, 여기서 i는 피벗값보다 작은 값들을 채우는 index로 사용됨. 
            i++; 
            // 피벗보다 작은 값을 왼쪽으로 이동, i == j 일 수도 있는데 그 때는 swap이 이루어 지지 않는다.  
            swap(arr[i], arr[j]);
        }
    }
    // 반복이 끝난 후 i + 1 위치에 피벗을 넣어줌  
    swap(arr[i + 1], arr[high]); 
    // 피벗의 최종 위치를 반환 
    return i + 1;
}

// 퀵소트 함수
static void quickSort(int arr[], int low, int high)
{
    // 엇갈리기 전까지만 실행 
    if (low < high) 
    {
        // 피벗 위치의 index를 반환해서 pi에 할당, 내부적으로 피벗을 기준으로 피벗값보다 작은 값은 왼쪽에 피벗값보다 큰 값은 오른쪽에 위치하게 됨. 
        int pi = partition(arr, low, high); // 분할 인덱스 
        quickSort(arr, low, pi - 1);  // 왼쪽 부분 정렬 
        quickSort(arr, pi + 1, high); // 오른쪽 부분 정렬 
    }
}

// 배열 출력 함수
static void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 메인 함수
int main() 
{
    int arr[] = { 10, 7, 8, 9, 1, 4, 5, 3, 2, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "정렬 전 배열: ";
    printArray(arr, n); 

    quickSort(arr, 0, n - 1);

    cout << "정렬 후 배열: ";
    printArray(arr, n);
    return 0;
}
