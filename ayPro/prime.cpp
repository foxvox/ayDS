#include <iostream>
#include <vector>
using namespace std;

static void sieve(int n)
{
    // 51���� ��ƾ� 0���� 50������ index�� ����� �� �ְ� �ȴ�. 
    vector<bool> isPrime(n + 1, true);
    // 0�� 1�� �Ҽ����� ���� 
    isPrime[0] = isPrime[1] = false; 

    for (int p = 2; p * p <= n; p++) 
    {
        if (isPrime[p])
        {
            // p��°�� �Ҽ��� ��� p�� ������� ��� �Ҽ��� �ƴ� ó���� �� 
            // p * 1, p * 2, . . . , p * (p - 1)�� ��� �Ҽ��� �ƴ϶�� �̹� �տ��� ó�� ��  
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
        // ���� true�� ����� index�� �Ҽ��� �ȴ�. 
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

