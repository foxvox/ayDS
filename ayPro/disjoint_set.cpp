#include <iostream>
#include <vector> 
#include <iomanip> 

using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    // �ʱ�ȭ: �� ���� �ڱ� �ڽ��� �θ�
    DisjointSet(int n)
    {
        parent.resize(n); 
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
        { 
            parent[i] = i; 
        }
    }

    // find: ��� ���� ���� => Ư���� ���Ұ� ���� ������ � �������� �˷��ִ� �Լ� => ��Ʈ ���� ��ȯ 
    int find(int x)
    { 
        if (parent[x] != x)
        { 
            // ��Ʈ ��带 ������ ������ ���� parent index�� �� ���� �ٸ���. 
            parent[x] = find(parent[x]);    // ��������� �θ� ã�Ƽ� ��� ���� 
        }

        return parent[x];
    }

    // union: ��ũ ������� ��ġ��
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; // �̹� ���� ���� 

        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // ���� �������� Ȯ��
    bool isConnected(int x, int y)
    {
        return find(x) == find(y); 
    }
};

int main()
{
    DisjointSet ds(7); // 0~5�� ���

    ds.unite(0, 1);
    ds.unite(0, 3);
    ds.unite(1, 2);
    ds.unite(4, 5);
    ds.unite(5, 6);

    // stream manipulator 
    cout << boolalpha << ds.isConnected(2, 4) << endl;

    return 0;
}
