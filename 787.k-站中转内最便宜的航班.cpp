/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 5010;
    struct Edges
    {
        int a, b, c;
    }edges[N];
    int dist[N], last[N];

    void bellman_ford(int k, int m, int s)
    {
        memset(dist, 0x3f, sizeof dist);

        dist[s] = 0;

        for(int i = 0; i <= k; i++)
        {
            memcpy(last, dist, sizeof dist);
            for(int j = 0; j < m; j++)
            {
                auto e = edges[j];
                dist[e.b] = min(dist[e.b], last[e.a] + e.c);
            }
        }
    }
    // 有限制的最短路算法
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        for(int i = 0; i < n; i++)
        {
            int a = flights[i][0], b = flights[i][1], c = flights[i][2];
            edges[i] = { a,b,c };
        }

        bellman_ford(k, m, src);

        if(dist[dst] > 0x3f3f3f3f / 2) return -1;
        else return dist[dst];
    }
};
// @lc code=end

