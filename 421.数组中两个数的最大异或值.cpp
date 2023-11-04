/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 6200010;
    int trie[N][2], index;

    void insert(int x)
    {
        int p = 0;
        for(int i = 30; i >= 0; i--)
        {
            int& u = trie[p][(x >> i) & 1];
            if(!u) u = ++index; 
            p = u;
        }
    }

    int search(int x)
    {
        int p = 0, res = 0;
        for(int i = 30; i >= 0; i--)
        {
            int s = x >> i & 1;
            if(trie[p][!s])
            {
                res += 1 << i;
                p = trie[p][!s]; 
            }
            else p = trie[p][s];
        }

        return res;
    }

    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        for(auto e : nums)
        {
            insert(e);
            
            res = max(res, search(e));
        }

        return res;
    }
};
// @lc code=end

