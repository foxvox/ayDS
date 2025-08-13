#include <iostream>
#include <vector>

int main()
{
    // denominations => 화폐 단위 

    int amount = 1370; // 거스름돈 총액
    std::vector<int> denominations = { 1000, 500, 100, 50, 10 }; // 화폐 단위
    std::vector<int> counts(denominations.size(), 0); // 각 화폐 개수 저장

    for (size_t i = 0; i < denominations.size(); ++i)
    {
        counts[i] = amount / denominations[i]; // 해당 단위로 줄 수 있는 최대 개수
        amount %= denominations[i]; // 남은 금액 갱신
    }

    // 결과 출력
    std::cout << "거스름돈 분배:\n";
    for (size_t i = 0; i < denominations.size(); ++i)
    {
        std::cout << denominations[i] << "원: " << counts[i] << "개\n";
    }

    return 0;
}
