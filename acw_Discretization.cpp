// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// typedef pair<int, int> PII;
// const int N = 300010;

// vector<PII> add, query;
// vector<int> alls;
// int a[N], s[N];
// int n, m;

// // 离散化映射
// int find(int x)
// {
//     int n = alls.size();
//     int l = 0, r = n - 1;

//     while(l < r)
//     {
//         int mid = (l + r) >> 1;
//         if(alls[mid] >= x) r = mid;
//         else l = mid + 1;
//     }

//     return r + 1;
// }

// int main()
// {
//     cin >> n >> m;

//     // 输入数组操作
//     for(int i = 0; i < n; i++)  
//     {
//         int x, y;
//         cin >> x >> y;
//         add.push_back({x, y});
//         alls.push_back(x);
//     }

//     // 输入查询
//     for(int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         query.push_back({x, y});
//         alls.push_back(x);
//         alls.push_back(y);
//     }
    
//     // 排序去重
//     sort(alls.begin(), alls.end());
//     alls.erase(unique(alls.begin(), alls.end()), alls.end());

//     // 数组操作
//     for(auto it : add)
//     {
//         int x = find(it.first);
//         a[x] += it.second;
//     }

//     // 前缀和数组
//     for(int i = 1; i <= alls.size(); i++) s[i] = s[i-1] + a[i];

//     // 输出
//     for(auto it : query)
//     {
//         int x = find(it.first), y = find(it.second);

//         cout << s[y] - s[x - 1] << endl;
//     }

//     return 0;
// }


#include <iostream>

using namespace std;

int n;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    cin >> n;

    while(n--)
    {
        int res, x;
        cin >> x;
        while(x)
        {
            x -= lowbit(x);
            res++;
        }
        cout << res << " ";
    }
    return 0;
}