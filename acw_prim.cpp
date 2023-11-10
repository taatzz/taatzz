// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 510, INF = 0x3f3f3f3f;

// int n, m, g[N][N], dist[N];
// bool st[N];

// int prim()
// {
//     memset(dist, 0x3f, sizeof dist);

//     int res = 0;
//     for(int i = 0; i < n; i++)
//     {
//         int t = -1;
//         for(int j = 1; j <= n; j++)
//             if(!st[j] && (t == -1 || dist[t] > dist[j]))
//                 t = j;
            
//         st[t] = 1;
//         if(i && dist[t] == 0x3f3f3f3f) return INF;
//         if(i) res += dist[t];
        
//         for(int j = 1; j <= n; j++)
//             dist[j] = min(dist[j], g[t][j]);
//     }

//     return res;
// }

// int main()
// {
//     memset(g, 0x3f, sizeof g);
//     cin >> n >> m;

//     while(m --)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         g[a][b] = g[b][a] = min(g[a][b], c);
//     }

//     int t = prim();
//     if(t == 0x3f3f3f3f) cout << "impossible" << endl;
//     else cout << t << endl;

//     return 0; 
// }


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;
struct Edge
{
    int a, b, w;
    bool operator<(Edge& e)
    {
        return w < e.w;
    }
}edges[M];

int n, m, p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    
    for(int i = 0; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b>> c;
        edges[i] = {a, b, c};
    }
    sort(edges, edges + m);

    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int pa = find(edges[i].a), pb = find(edges[i].b);
        if(pa != pb)
        {
            p[pa] = pb;
            res += edges[i].w;
            cnt++;
        }
    }

    if(cnt < n - 1) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}