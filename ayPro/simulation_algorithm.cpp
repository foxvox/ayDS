#include <iostream>
#include <vector>
#include <cmath> 
#include <iomanip>  
using namespace std;

struct Particle 
{
    double x, y;       // ��ġ
    double vx, vy;     // �ӵ�

    void update(double dt) 
    {
        x += vx * dt;
        y += vy * dt;
    }

    void print() const 
    {
        cout << "Position: (" << setw(2) << x << ", " << setw(3) << y << ")\n";
    }
};

int main() 
{
    Particle p = { 0.0, 0.0, 1.0, 0.5 };    // �ʱ� ��ġ (0,0), �ӵ� (1, 0.5)
    double   timeStep = 1.0;                // �ð� ����
    int      steps = 10;                    // �ùķ��̼� �ݺ� Ƚ��

    for (int i = 0; i < steps; ++i) 
    {
        p.update(timeStep);
        cout << "Step " << setw(2) << i + 1 << ": ";
        p.print(); 
    }

    return 0;
}
