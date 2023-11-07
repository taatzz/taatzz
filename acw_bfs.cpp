
// 图的广度优先搜素
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 100010;

// int n, m;
// int h[N], e[N], ne[N], idx;
// int d[N];

// void add(int a, int b)
// {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }

// void bfs(int u)
// {
//     int q[N];
//     int hh = 0, tt = -1;
//     q[++tt] = u;
//     d[u] = 0;

//     while(hh <= tt)
//     {
//         auto t = q[hh++];
//         for(int i = h[t]; i != -1; i = ne[i])
//         {
//             int j = e[i];
//             if(d[j] == -1)
//             {
//                 d[j] = d[t] + 1;
//                 q[++tt] = j;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     memset(h, -1, sizeof h);
//     memset(d, -1, sizeof d);
//     while(m --)
//     {
//         int a, b;
//         cin >> a >> b;
//         add(a, b);
//     }

//     bfs(1);

//     cout << d[n] << endl;

//     return 0;
// }



#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void top_sort()
{
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++)
        if(d[i] == 0)
            q[++ tt] = i;

    while(hh <= tt)
    {
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    if(tt == n - 1)
    {
        for(int i = 0; i < n; i++) cout << q[i] << " ";
        cout << endl;
    }
    else cout << -1 << endl;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;
    }

    top_sort();

    return 0;
}