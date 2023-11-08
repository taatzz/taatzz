// 朴素Dijkstra
// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N = 510;
// int n, m, g[N][N], d[N];
// bool st[N];

// int Dijkstra()
// {
//     d[1] = 0;
//     for(int i = 0; i < n; i++)
//     {
//         int t = -1;
//         for(int j = 1; j <= n; j++)
//             if(!st[j] && (t == -1 || d[j] < d[t]))
//                 t = j;

//         st[t] = 1;
//         for(int k = 1; k <= n; k++)
//         {
//             d[k] = min(d[k], d[t] + g[t][k]);
//         }
//     }

//     if(d[n] > 0x3f3f3f3f / 2) return -1;
//     else return d[n];
// }

// int main()
// {
//     cin >> n >> m;

//     memset(g, 0x3f, sizeof g);
//     memset(d, 0x3f, sizeof d);
//     while(m --)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         g[a][b] = min(g[a][b], c);
//     }

//     cout << Dijkstra() << endl;

//     return 0;
// }


// 堆优化Dijkstra
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 150010;
int n, m, d[N], h[N], e[N], ne[N], w[N], idx;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    priority_queue<PII, vector<PII>, greater<PII> > q; // 距离，顶点
    d[1] = 0;
    
    q.push( {0, 1} );
    
    while(q.size())
    {
        auto t = q.top();
        q.pop();
        
        int dist = t.first, ver = t.second;
        
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] > dist + w[i])
            {
                d[j] = dist + w[i];
                q.push({d[j], j});
            }
        }
    }

    
    if(d[n] == 0x3f3f3f3f) return -1;
    else return d[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    cout << Dijkstra() << endl;
    
    return 0;
}