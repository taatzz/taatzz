#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1900010;
    int n, ind = 0;
    int son[N][2];
    int pass[N]; // 统计当前节点的数量

    void insert(int x)
    {
        int p = 0;
        for(int i = 19; i >= 0; i--)
        {
            int u = x >> i & 1;
            if(!son[p][u])
            {
                son[p][u] = ++ind;
            } 
            p = son[p][u];
            ++pass[p];
        }
    }

    void remove(int x)
    {
        int p = 0;
        for(int i = 19; i >= 0; i--)
        {
            int u = x >> i & 1;
            if(-- pass[son[p][u]] == 0)
            {
                son[p][u] = 0;
                return;
            }
            p = son[p][u];
        }
    }

    int find(int x)
    {
        int p = 0, res = 0;
        for(int i = 19; i >= 0; i--)
        {
            int u = x >> i & 1;
            if(son[p][!u])
            {
                res += 1 << i;
                p = son[p][!u];
            }
            else p = son[p][u];
        }
        
        return res;
    }
    
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = -1;
        
        int l = 0;
        for(auto e : nums)
        {
            insert(e);

            while(nums[l] * 2 < e)
            {
                remove(nums[l]);
                l++;
            }
            int t = find(e);
            
            res = max(t, res);
        }
        
        return res;
    }
};