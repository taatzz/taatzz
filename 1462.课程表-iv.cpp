/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;


class Solution {
public:
    static const int N = 110, M = 5010;
    int h[N], e[M], ne[M], idx;
    int in[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void topsort(vector<unordered_set<int> >& tmp, int n)
    {
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!in[i]) q.push(i);

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                for(auto a : tmp[t])
                    tmp[j].insert(a);
                tmp[j].insert(t);
                if(--in[j] == 0)
                    q.push(j);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        memset(h, -1, sizeof h);
        for(auto e : pre)
        {
            int a = e[0], b = e[1];
            add(a, b);
            in[b] ++;
        }
        vector<unordered_set<int> > tmp(n);
        topsort(tmp, n);

        vector<bool> res;
        for(auto e : queries)
        {
            int u = e[0], v = e[1];
            if(tmp[v].find(u) != tmp[v].end()) res.push_back(1);
            else res.push_back(0);
        }

        return res;
    }
};
// @lc code=end

