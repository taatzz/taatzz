/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& a, int x)
    {
        int cnt = 0;
        for(auto e : a)
        {
            if(e >= x)
                cnt++;
        }

        return cnt >= x;
    }
    // 二分答案
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int l = 0, r = n;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(citations, mid)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

