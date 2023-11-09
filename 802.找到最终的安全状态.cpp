#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 40010;
    int h[N], e[N], ne[N], in[N], idx = 0;
    vector<int> res;

    void add(int a, int b)
    {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    void topsort(int n)
    {
        int q[N], hh = 0, tt = -1;
        for(int i = n - 1; i >= 0; i--)
            if(!in[i]) q[++tt] = i;

        while(hh <= tt)
        {
            int t = q[hh++];

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(--in[j] == 0)
                    q[++tt] = j;
            }
        }
        for(int i = 0; i< n; i++)
            if(in[i] == 0) res.push_back(i);

    }

    // 反向建图，拓扑排序，对于答案从小到大输出
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        memset(h, -1, sizeof h);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                add(graph[i][j], i);
                in[i] ++;
            }
        }
        topsort(n);

        return res;
    }
};