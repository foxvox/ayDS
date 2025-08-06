#include <iostream> 

using namespace std;

int main()
{
#pragma region 인플레이스정렬 

#pragma region 거품정렬 
    int arr[] = { 5, 7, 3, 1, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 거품 정렬 알고리즘
    for (int i = 0; i < n - 1; ++i) // index 0 ~ 3까지 바뀌게 됨. 
    {
        // i가 0일 때, 0 ~ 3까지 순회 => 순회 후 4index에 최대값 들어감. i가 1일 때 0 ~ 2까지 순회 => 순회 후 3index에 2번째 큰 값이 들어감. 
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

    // 결과 출력
    cout << "오름차순 정렬 결과: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#pragma endregion

#pragma endregion

}