#include <iostream>
// ���� �迭(dynamic array) �ڷᱸ�� 
#include <vector> 
// �ؽ����̺� ����� �ڷᱸ�� 
#include <unordered_map> 
using namespace std; 

int main()
{
    // ������ vector �ʱ�ȭ
    std::vector<int> numbers = { 1, 2, 3, 2, 4, 1, 2, 3, 5 }; 

    // �� ������ ���� Ƚ���� ������ map 
    std::unordered_map<int, int> countMap; 

    // ���� Ƚ�� ���
    for (int num : numbers)
    {
        countMap[num]++; 
    }

    cout << "numbers vector�� ���� : "; 
    for (int num : numbers)
    {
        cout << num << "  "; 
    } 
    cout << endl; 

    // ��� ���
    std::cout << "���ں� ���� Ƚ��:\n"; 
    for (const auto& pair : countMap) 
    {
        std::cout << pair.first << " : " << pair.second << "��\n"; 
    }

    return 0;
}
