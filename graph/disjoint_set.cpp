#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int a)
    {
        return parent[a] == a ? a : parent[a] = findUltimateParent(parent[a]);
    }

    void UnionByRank(int a, int b)
    {
        int pa = findUltimateParent(a), pb = findUltimateParent(b);
        if (pa != pb)
        {
            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else
                parent[pb] = pa;
            rank[pa] += rank[pa] == rank[pb];
        }
    }
};