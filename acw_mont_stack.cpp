#define  _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <vector>

// using namespace std;

// const int N = 100010;
// int n, a[N], s[N];
// int hh = -1;

// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> a[i];

//     // vector<int> res(n ,-1);
//     // // O(n^2)
//     // for(int i = 0; i < n; i++)
//     // {
//     //     for(int j = i - 1; j >= 0; j--)
//     //     {
//     //         if(a[j] < a[i])
//     //         {
//     //             res[i] = a[j];
//     //             break;
//     //         }
//     //     }
//     // }

//     // for(auto e : res) cout << e << " ";

//     for(int i = 0; i < n; i++)
//     {
//         while(hh >= 0 && a[s[hh]] >= a[i]) hh--;
//         if(hh >= 0) cout << a[s[hh]] << " ";
//         else cout << -1 << " ";
//         s[++hh] = i;
//     }

//     return 0;
// }


#include <iostream>

using namespace std;

const int N = 1000010;
int n, k, nums[N];
int q[N], hh = 0, tt = -1;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) scanf("%d", &nums[i]);

    // O(n^2)
    // for(int i = 0; i < n - k; i++)
    // {
    //     int res = INT_MAX;
    //     for(int j = i; j < k + i; j++)
    //     {
    //         res = min(res, nums[j]);
    //     }
    //     cout << res << " ";
    // }
    // cout << endl;

    // for(int i = 0; i < n - k; i++)
    // {
    //     int res = INT_MIN;
    //     for(int j = i; j < k + i; j++)
    //     {
    //         res = max(res, nums[j]);
    //     }
    //     cout << res << " ";
    // }
    // cout << endl;

    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && i - k + 1 > q[hh]) hh++;

        while(hh <= tt && nums[q[tt]] >= nums[i]) tt--;
        q[++tt] = i;

        if(i >= k - 1) cout << nums[q[hh]] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && i - k + 1 > q[hh]) hh++;

        while(hh <= tt && nums[q[tt]] <= nums[i]) tt--;
        q[++tt] = i;

        if(i >= k - 1) cout << nums[q[hh]] << " ";
    }
    cout << endl;

    return 0;
}