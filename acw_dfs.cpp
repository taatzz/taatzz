// #include <iostream>

// using namespace std;

// const int N = 10;
// int n;
// bool col[N], dg[N * 2], udg[N * 2], row[N]; // 列，对角线，反对角线
// char g[N][N];

// void dfs(int x)
// {
//     if(x == n)
//     {
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//                 cout << g[i][j];
//             cout << endl;
//         }
//         return;
//     }

//     for(int i = 0; i < n; i++)
//     {
//         if(!col[i] && !dg[x + i] && !udg[n - x + i])
//         {
//             g[x][i] = 'Q';
//             col[i] = dg[x + i] = udg[n - x + i] = true;
//             dfs(x + 1);
//             col[i] = dg[x + i] = udg[n - x + i] = false;
//             g[x][i] = '.';
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n; j++)
//             g[i][j] = '.';
//     }

//     dfs(0);

//     return 0;
// }

// void dfs(int x, int y, int u)
// {
//     if(u > n) return;
//     if(y == n) y = 0, x++;

//     if(x == n)
//     {
//         if(x == n)
//         {
//             for(int i = 0; i < n; i++)
//             {
//                 for(int j = 0; j < n; j++)
//                     cout << g[i][j];
//                 cout << endl;
//             }
//             cout << endl;
//         }
//         return;
//     }
//     g[x][y] = '.';
//     dfs(x, y + 1, u);

//     if(!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
//     {
//         g[x][y] = 'Q';
//         row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
//         dfs(x, y + 1, u + 1);
//         row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
//         g[x][y] = '.';
//     }
// }

// int main()
// {
//     cin >> n;

//     dfs(0, 0, 0);

//     return 0;
// }



// 图/树的深度优先遍历

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
int n, h[N], e[N * 2], ne[N * 2], idx;
bool st[N];
int ans = N;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;

    int size = 0, sum = 0; // size保存联通分量的最大值，sum保存当前节点的子节点数量
    for(int i = h[u]; i != - 1; i = ne[i])
    {
        int j = e[i];
        if(st[j] == true) continue;

        int s = dfs(j);
        size = max(size, s); // 子树每一个联通求最大值
        sum += s;
    }

    size = max(size, n - sum - 1); // 节点总数 - 子树联通分量数量 求最大值
    ans = min(ans, size); // 更新答案

    return sum + 1;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);

     cout << ans;

    return 0;
}