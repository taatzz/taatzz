/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 5010;
    int h[N], e[N], ne[N], d[N], idx = 0;
    void add(int a, int b)
    {
        e[idx] = a;
        ne[idx] = h[b];
        h[b] = idx++;
    }

    bool top_sort(int n)
    {
        int q[N];
        int hh = 0, tt = -1;

        for(int i = 0; i < n; i++)
        {
            if(!d[i])
                q[++tt] = i;
        }

        while(hh <= tt)
        {
            auto t = q[hh++];
            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(-- d[j] == 0)
                    q[++tt] = j;
            }
        }

        return tt == n - 1;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);

        for(auto e : prerequisites)
        {
            add(e[0], e[1]);
            d[e[0]] += 1;
        }
        return top_sort(numCourses);
    }
};
// @lc code=end

