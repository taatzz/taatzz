/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>

using namespace std;

// class Solution {
// public:
//     map<string, int> hash;
//     vector<string> findRepeatedDnaSequences(string s) {
        
//         int n = s.size();
//         for(int i = 9; i < n; i++)
//         {
//             hash[s.substr(i - 9, 10)] += 1;
//         }
//         vector<string> res;
//         for(auto it : hash)
//         {
//             if(it.second > 1) res.push_back(it.first);
//         }

//         return res;
//     }
// };
// @lc code=end


class Solution {
public:
    static const int N = 100010, Q = 131;
    typedef unsigned long long ULL;
    ULL h[N], q[N];

    ULL get(int l, int r)
    {
        return h[r] - h[l - 1] * q[r - l + 1];
    }

    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        q[0] = 1;
        for(int i = 1; i <= s.size(); i++)
        {
            h[i] = h[i - 1]  * Q + s[i - 1];
            q[i] = q[i-1] * Q;
        }
        vector<string> res;
        map<ULL, int> hash;
        for(int i = 1; i + 10 - 1 <= n; i++)
        {
            int j = i + 10 - 1;
            auto t = get(i, j);
            int cnt = 0;
            if(hash.find(t) != hash.end())
            {
                cnt = hash[t];
            }
            if(cnt == 1)
                res.push_back(s.substr(i - 1, 10));
            hash[t] = cnt + 1;
        } 

        return res;
    }
};
