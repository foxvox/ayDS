#include <iostream>
#include <vector>

int main()
{
    // denominations => ȭ�� ���� 

    int amount = 1370; // �Ž����� �Ѿ�
    std::vector<int> denominations = { 1000, 500, 100, 50, 10 }; // ȭ�� ����
    std::vector<int> counts(denominations.size(), 0); // �� ȭ�� ���� ����

    for (size_t i = 0; i < denominations.size(); ++i)
    {
        counts[i] = amount / denominations[i]; // �ش� ������ �� �� �ִ� �ִ� ����
        amount %= denominations[i]; // ���� �ݾ� ����
    }

    // ��� ���
    std::cout << "�Ž����� �й�:\n";
    for (size_t i = 0; i < denominations.size(); ++i)
    {
        std::cout << denominations[i] << "��: " << counts[i] << "��\n";
    }

    return 0;
}
