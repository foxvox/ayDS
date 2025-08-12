#include <iostream> 
#include <cstdint>
#include <stdexcept>  
#define ULL unsigned long long  

using namespace std; 

static ULL fibo(ULL index) 
{
    if (index == 0) 
    {
        throw std::invalid_argument("index는 1부터 시작합니다.");
    } 

    if (index <= 2) 
        return 1; 

    ULL a = 1, b = 1; 
    for (ULL i = 3; i <= index; ++i) 
    {
        int next = a + b; 
        a = b; 
        b = next;
    }
    return b;
}

int main() 
{
    for (ULL i = 1; i < 47; i++) 
    {
        cout << fibo(i) << endl;  
    }

    return 0;
}

