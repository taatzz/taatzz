// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 10010;
// int n, m, k;
// struct Edge
// {
//     int a, b, c;
// }edges[N];
// int dist[N], last[N];

// void bellman_ford()
// {
//     memset(dist, 0x3f, sizeof dist);

//     dist[1] = 0;
//     for(int i = 0; i < k; i++)
//     {
//         memcpy(last, dist, sizeof dist);
//         for(int i = 0; i < m; i++)
//         {
//             auto e = edges[i];
//             dist[e.b] = min(dist[e.b], last[e.a] + e.c);
//         }
//     }

// }

// int main()
// {
//     cin >> n >> m >> k;
//     for(int i = 0; i < m; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         edges[i] = { a,b,c };
//     }

//     bellman_ford();
//     if(dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
//     else cout << dist[n] << endl;

//     return 0;
// }



// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 100010;
// int n, m, h[N], e[N], ne[N], w[N], d[N], idx;
// bool st[N];

// void add(int a, int b, int c)
// {
//     e[idx] = b;
//     w[idx] = c;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }

// void spfa()
// {
//     memset(d, 0x3f, sizeof d);
//     d[1] = 0;
//     int q[N], hh = 0, tt = -1;
//     q[++tt] = 1;
//     st[1] = 1;

//     while(hh <= tt)
//     {
//         int t = q[hh++];
//         st[t] = 0;
//         for(int i = h[t]; i != - 1; i = ne[i])
//         {
//             int j = e[i];
//             if(d[j] > d[t] + w[i]) 
//             {
//                 d[j] = d[t] + w[i];
//                 if(!st[j])
//                 {
//                     q[++tt] = j;
//                     st[j] = 1;
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     memset(h, -1, sizeof h);
//     while(m --)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         add(a, b, c);
//     }
//     spfa();

//     if(d[n] == 0x3f3f3f3f) cout << "impossible" << endl;
//     else cout << d[n] << endl;

//     return 0;
// }


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m, h[N], e[M], ne[M], cnt[N], w[M], idx;
int d[N];
bool st[N];

void add(int a,int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa()
{
    queue<int> q;
    for(int i = 1;i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] > d[t] + w[i])
            {
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >=  n) return true;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if(spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}