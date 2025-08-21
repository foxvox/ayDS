#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Kruskal
{
public:
    class Edge
    {
    public: 
        int vertexX, vertexY, weight;

        Edge(int vx, int vy, int w)
            : vertexX(vx), vertexY(vy), weight(w)
        {
        }

        // 정렬을 위한 비교 연산자
        bool operator<(const Edge& other) const
        {
            return weight < other.weight;
        }
    };

public:
    vector<Edge*> edgeList; 
    vector<int>   parent; 

    // 간선 삽입 
    void Insert(int vertexX, int vertexY, int weight)
    {
        edgeList.push_back(new Edge(vertexX, vertexY, weight));
    }

    // 초기화: 각 정점은 자기 자신이 부모
    void Initialize(int vertexCount)
    {
        parent.resize(vertexCount);
        for (int i = 0; i < vertexCount; ++i)
        {
            parent[i] = i;
        }
    }

    // find: 경로 압축, root를 찾아서 return 
    int Find(int x)
    {
        if (parent[x] != x) 
        {
            parent[x] = Find(parent[x]);
        }

        return parent[x]; 
    }

    // union: 두 집합을 합침
    void Union(int a, int b)
    {
        int rootA = Find(a);
        int rootB = Find(b);

        if (rootA != rootB)
        {
            parent[rootB] = rootA;
        }
    }

    // MST 계산 => MST means Minimum Spanning Tree 
    void BuildMST()
    {
        sort(edgeList.begin(), edgeList.end(), [](Edge* a, Edge* b) { return *a < *b; }); 

        int totalCost = 0; 
        cout << "최소 신장 트리 간선 목록:\n";  

        for (Edge* e : edgeList) 
        {
            if (Find(e->vertexX) != Find(e->vertexY))
            {
                Union(e->vertexX, e->vertexY);
                totalCost += e->weight; 
                cout << e->vertexX << " - " << e->vertexY << " (비용: " << e->weight << ")\n";
            }
        }

        cout << "총 비용: " << totalCost << endl; 
    }

    // 소멸자: 동적 할당된 간선 메모리 해제
    ~Kruskal()
    {
        for (Edge* e : edgeList)
        {
            delete e;
        }
    }
};

int main()
{ 
    Kruskal k;
    int vertexCount = 8; // 정점 수: 0~7  
    k.Initialize(vertexCount);

    // 간선 삽입
    k.Insert(1, 7, 12);
    k.Insert(1, 4, 30);
    k.Insert(1, 2, 71);
    k.Insert(1, 5, 15);
    k.Insert(2, 4, 23);
    k.Insert(2, 5, 65);
    k.Insert(3, 5, 18);
    k.Insert(3, 6, 36);
    k.Insert(4, 7, 13);
    k.Insert(5, 6, 44);
    k.Insert(5, 7, 79);

    // MST 비용 계산하는 함수 
    k.BuildMST();

    return 0;
}
