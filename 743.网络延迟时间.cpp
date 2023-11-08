/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 110;
    int g[N][N], d[N];
    bool st[N];

    void Dijkstra(int n, int k)
    {
        d[k] = 0;

        for(int i = 0; i < n; i++)
        {
            int t = -1;
            for(int j = 1; j <= n; j++)
            {
                if(!st[j] && (t == -1 || d[t] > d[j]))
                    t = j;
            }

            st[t] = 1;
            for(int j = 1; j <= n; j++)
                d[j] = min(d[j], d[t] + g[t][j]);
        }
    }

    // 单源最短路算法
    // 第k个点到每一个点的时间，需要知道第k个节点到每一个节点的最短时间
    // 结果取最大值
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(g, 0x3f, sizeof g);
        memset(d, 0x3f, sizeof d);
        for(auto e : times)
        {
            int a = e[0], b = e[1], c = e[2];
            g[a][b] = min(g[a][b], c);
        }

        Dijkstra(n, k);

        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            if(d[i] == 0x3f3f3f3f)
                return -1;
            res = max(res, d[i]);
        }

        return res;
    }
};
// @lc code=end

