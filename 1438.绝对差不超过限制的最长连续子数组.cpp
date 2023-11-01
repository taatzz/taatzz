/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool check(vector<int>& nums, int k, int l)
    {
        int q[100010], q1[100010];
        int hh = 0, tt = -1;
        int hh1 = 0, tt1 = -1;
        vector<int> Max, Min;
        // 模板求窗口的最大最小值
        for(int i = 0; i < nums.size(); i++)
        {
            if(hh <= tt && i - k + 1 > q[hh]) hh++;
            if(hh1 <= tt1 && i - k + 1 > q1[hh1]) hh1++;

            while(hh <= tt && nums[i] >= nums[q[tt]]) tt--;
            while(hh1 <= tt1 && nums[i] <= nums[q1[tt1]]) tt1--;
        
            q[++tt] = i;
            q1[++tt1] = i;

            if(i >= k - 1)
            {
                Max.push_back(nums[q[hh]]);
                Min.push_back(nums[q1[hh1]]);
            }
        }

        // 判断是否符合条件
        for(int i = 0; i < Max.size(); i++)
        {
            int len = abs(Max[i] - Min[i]);
            // 这里我们只要找到一个符合条件的窗口就可以我们求的时最长的长度
            if(len <= l) 
                return true;
        }

        return false;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 0, r = n;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
        // 当前窗口值符合我们向右边找看是否有更大的窗口值
            if(check(nums, mid, limit)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

