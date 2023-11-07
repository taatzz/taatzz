/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N], ne[N], d[N], idx = 0;
    void add(int a, int b)
    {
        e[idx] = a;
        ne[idx] = h[b];
        h[b] = idx++;
    }
    
    vector<int> top_sort(int n)
    {
        vector<int> res;
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

        if(tt == n - 1)
        {
            for(int i = 0; i < n; i++)
                res.push_back(q[i]);
        }

        return res;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

