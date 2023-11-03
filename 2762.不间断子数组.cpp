/*
 * @lc app=leetcode.cn id=2762 lang=cpp
 *
 * [2762] 不间断子数组
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    typedef long long LL;
    long long continuousSubarrays(vector<int> &nums) {
    LL ans = 0;
    map<int, int> cnt;
    int n = nums.size();
    for (int l = 0, r = 0; r < n; r++) {
        cnt[nums[r]]++;
        // end指向的是最后一个元素的下一个位置，可以使用rbegin()直接获取最后一个位置
        // while ((--cnt.end())->first - cnt.begin()->first > 2) {
        while (cnt.rbegin()->first - cnt.begin()->first > 2) {
            cnt[nums[l]]--;
            if (cnt[nums[l]] == 0) {
                cnt.erase(nums[l]);
            }
            l++;
        }
        ans += r - l + 1;
    }
    return ans;
}
};
// @lc code=end

