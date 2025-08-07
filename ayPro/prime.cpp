#include <iostream>
#include <vector>
using namespace std;

static void sieve(int n)
{
    // 51개를 잡아야 0부터 50까지의 index를 사용할 수 있게 된다. 
    vector<bool> isPrime(n + 1, true);
    // 0과 1은 소수에서 제외 
    isPrime[0] = isPrime[1] = false; 

    for (int p = 2; p * p <= n; p++) 
    {
        if (isPrime[p])
        {
            // p번째가 소수인 경우 p의 배수들은 모두 소수가 아닌 처리를 함 
            // p * 1, p * 2, . . . , p * (p - 1)은 모두 소수가 아니라고 이미 앞에서 처리 됨  
            for (int i = p * p; i <= n; i += p) 
            {
                isPrime[i] = false; 
            }
        }
    }

    // Print all prime numbers 
    cout << "Prime numbers up to " << n << ": "; 
    for (int i = 2; i <= n; i++) 
    {
        // 값이 true인 경우의 index가 소수가 된다. 
        if (isPrime[i])
        {
            cout << i << " "; 
        } 
    } 
    cout << endl; 
}

int main()
{
    int n = 50; 
    sieve(n); 
} 

