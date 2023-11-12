#include <iostream>
#include <cstring>
#include <algorithm>

using  namespace std;

const int N = 100010;
int n, m, h[N], e[N * 2], ne[N * 2], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int x)
{
    color[u] = x;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!color[j])
        {
            if(!dfs(j, 3 - x)) return false;
        }
        else if(color[j] == x) return false;
    }

    return true;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);

    while(m --)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!dfs(i, 1)) 
            {
                flag = false;
                break;
            }
        }
    }

    if(flag) cout << "Yes";
    else cout << "No";

    return 0;
}