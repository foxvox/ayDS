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
    // 초기화: 각 노드는 자기 자신이 부모
    DisjointSet(int n)
    {
        parent.resize(n); 
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
        { 
            parent[i] = i; 
        }
    }

    // find: 경로 압축 적용 => 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 함수 => 루트 값을 반환 
    int find(int x)
    { 
        if (parent[x] != x)
        { 
            // 루트 노드를 제외한 나머지 노드는 parent index와 그 값이 다르다. 
            parent[x] = find(parent[x]);    // 재귀적으로 부모를 찾아서 경로 압축 
        }

        return parent[x];
    }

    // union: 랭크 기반으로 합치기
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; // 이미 같은 집합 

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

    // 같은 집합인지 확인
    bool isConnected(int x, int y)
    {
        return find(x) == find(y); 
    }
};

int main()
{
    DisjointSet ds(7); // 0~5번 노드

    ds.unite(0, 1);
    ds.unite(0, 3);
    ds.unite(1, 2);
    ds.unite(4, 5);
    ds.unite(5, 6);

    // stream manipulator 
    cout << boolalpha << ds.isConnected(2, 4) << endl;

    return 0;
}
