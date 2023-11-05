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

class Solution {
public:
    map<string, int> hash;
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n = s.size();
        for(int i = 9; i < n; i++)
        {
            hash[s.substr(i - 9, 10)] += 1;
        }
        vector<string> res;
        for(auto it : hash)
        {
            if(it.second > 1) res.push_back(it.first);
        }

        return res;
    }
};
// @lc code=end

