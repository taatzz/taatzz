/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         sort(potions.begin(), potions.end());
//         vector<pair<int, int>> tmp;
//         int n = spells.size(), m = potions.size();
//         for(int i = 0; i < n; i++)
//             tmp.push_back({spells[i], i});
//         sort(tmp.begin(), tmp.end());

//         vector<int> res(n);
//         for(int i = 0, j = m - 1; i < n; i++)
//         {
//             auto t = tmp[i];
//             int x = t.first, d = t.second;
//             while(j >= 0 && (long long) x * potions[j] * 1ll >= success)
//                 j--;
//             res[d] = m - j - 1;
//         }

//         return res;
//     }
// };
// @lc code=end


class Solution {
public:
    int find(vector<int>& p, double x)
    {
        int l = 0, r = p.size() - 1;
        while(l < r)
        {
            int mid = p[(l + r ) >> 1];
            if(p[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(p[r] >= x) return p.size() - r; 
        else return 0;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> res;
        for(auto e : spells)
        {
            int x;
            if(success % e == 0) x = success / e * 1.0;
            else x = success / e + 1 * 1.0;
            res.push_back(find(potions, x));
        }

        return res;
    }
};