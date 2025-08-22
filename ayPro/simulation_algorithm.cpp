#include <iostream>
#include <vector>
#include <cmath> 
#include <iomanip>  
using namespace std;

struct Particle 
{
    double x, y;       // 위치
    double vx, vy;     // 속도

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
    Particle p = { 0.0, 0.0, 1.0, 0.5 };    // 초기 위치 (0,0), 속도 (1, 0.5)
    double   timeStep = 1.0;                // 시간 간격
    int      steps = 10;                    // 시뮬레이션 반복 횟수

    for (int i = 0; i < steps; ++i) 
    {
        p.update(timeStep);
        cout << "Step " << setw(2) << i + 1 << ": ";
        p.print(); 
    }

    return 0;
}
