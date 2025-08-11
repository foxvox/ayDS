#include <iostream>
// 동적 배열(dynamic array) 자료구조 
#include <vector> 
// 해시테이블 기반의 자료구조 
#include <unordered_map> 
using namespace std; 

int main()
{
    // 정수형 vector 초기화
    std::vector<int> numbers = { 1, 2, 3, 2, 4, 1, 2, 3, 5 }; 

    // 각 숫자의 등장 횟수를 저장할 map 
    std::unordered_map<int, int> countMap; 

    // 등장 횟수 계산
    for (int num : numbers)
    {
        countMap[num]++; 
    }

    cout << "numbers vector의 원소 : "; 
    for (int num : numbers)
    {
        cout << num << "  "; 
    } 
    cout << endl; 

    // 결과 출력
    std::cout << "숫자별 등장 횟수:\n"; 
    for (const auto& pair : countMap) 
    {
        std::cout << pair.first << " : " << pair.second << "번\n"; 
    }

    return 0;
}
