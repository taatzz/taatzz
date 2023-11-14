#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, k, dist[N][N];

void floyd()
{
    for(int k  = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}

int main()
{
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    floyd();

    while(k --)
    {
        int a, b;
        cin >> a >> b;
        int t = dist[a][b];

        if(t > INF / 2) cout << "impossible" << endl;
        else cout << t << endl;
    }

    return 0;
}