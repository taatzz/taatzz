// #include <iostream>
// #include <string>

// using namespace std;

// const int N = 100010;
// int n, index = 0, son[N][26], cnt[N];
// son[][]存储树中每个节点的子节点, 第一维表示树的总结点数, 第二维表示每个结点最多有几个子结点
// son中存储的是数字
// cnt[]存储以每个节点结尾的单词数量

// void Insert(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int x = s[i] - 'a';
//         if(!son[p][x]) son[p][x] = ++index;
//         p = son[p][x];
//     }
//     cnt[p]++;
// }

// int query(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int x = s[i] - 'a';
//         if(!son[p][x]) return 0;
//         p = son[p][x];
//     }

//     return cnt[p];
// }

// int main()
// {
//     cin >> n;

//     while(n--)
//     {
//         char c;
//         cin >> c;
//         if(c == 'I')
//         {
//             string s;
//             cin >> s;
//             Insert(s);
//         }
//         else
//         {
//             string s;
//             cin >> s;
//             cout << query(s) << endl;
//         }
//     }

//     return 0;
// }


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3100010;

int n, a[N], son[M][2], index;

void Insert(int x)
{
    int p = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = (x >> i) & 1;
        if(!son[p][u]) son[p][u] = ++index;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if(son[p][!u])
        {
            res += 1 << i;
            p = son[p][u];
        }
        else p = son[p][u];
    }

    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n ;i ++) cin >> a[i];

    int res = 0;
    for(int i = 0; i < n; i++) 
    {
        Insert(a[i]);
        res = max(res, query(a[i]));
    }

    cout << res << endl;

    return 0;
}
