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

        // ������ ���� �� ������
        bool operator<(const Edge& other) const
        {
            return weight < other.weight;
        }
    };

public:
    vector<Edge*> edgeList; 
    vector<int>   parent; 

    // ���� ���� 
    void Insert(int vertexX, int vertexY, int weight)
    {
        edgeList.push_back(new Edge(vertexX, vertexY, weight));
    }

    // �ʱ�ȭ: �� ������ �ڱ� �ڽ��� �θ�
    void Initialize(int vertexCount)
    {
        parent.resize(vertexCount);
        for (int i = 0; i < vertexCount; ++i)
        {
            parent[i] = i;
        }
    }

    // find: ��� ����, root�� ã�Ƽ� return 
    int Find(int x)
    {
        if (parent[x] != x) 
        {
            parent[x] = Find(parent[x]);
        }

        return parent[x]; 
    }

    // union: �� ������ ��ħ
    void Union(int a, int b)
    {
        int rootA = Find(a);
        int rootB = Find(b);

        if (rootA != rootB)
        {
            parent[rootB] = rootA;
        }
    }

    // MST ��� => MST means Minimum Spanning Tree 
    void BuildMST()
    {
        sort(edgeList.begin(), edgeList.end(), [](Edge* a, Edge* b) { return *a < *b; }); 

        int totalCost = 0; 
        cout << "�ּ� ���� Ʈ�� ���� ���:\n";  

        for (Edge* e : edgeList) 
        {
            if (Find(e->vertexX) != Find(e->vertexY))
            {
                Union(e->vertexX, e->vertexY);
                totalCost += e->weight; 
                cout << e->vertexX << " - " << e->vertexY << " (���: " << e->weight << ")\n";
            }
        }

        cout << "�� ���: " << totalCost << endl; 
    }

    // �Ҹ���: ���� �Ҵ�� ���� �޸� ����
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
    int vertexCount = 8; // ���� ��: 0~7  
    k.Initialize(vertexCount);

    // ���� ����
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

    // MST ��� ����ϴ� �Լ� 
    k.BuildMST();

    return 0;
}
