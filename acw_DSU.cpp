#define _CRT_SECURE_NO_WARNINGS
// #include <iostream>


// using namespace std;

// const int N = 100010;

// int n, m, father[N];

// int find(int x)
// {
//     if(father[x] != x) father[x] = find(father[x]);
//     return father[x];
// }

// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i < n; i++) father[i] = i;

//     while(m--)
//     {
//         char c;
//         cin >> c;
//         int a, b;
//         cin >> a >> b;
//         if(c == 'M')
//         {
//             if(find(a) != find(b))
//             {
//                 father[find(a)] = find(b);
//             }
//         }
//         else
//         {
//             if(find(a) == find(b))
//                 cout << "Yes" << endl;
//             else
//                 cout << "No" << endl;
//         }
//     }

//     return 0;
// }


// #include <iostream>

// using namespace std;

// const int N = 100010;
// int n, m;
// int p[N], cnt[N];

// int find(int x)
// {
//     if(p[x] != x) p[x] = find(p[x]);
//     return p[x];
// }

// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++)
//     {
//         p[i] = i;
//         cnt[i] = 1;
//     }
    
//     while (m -- )
//     {
//         string s;
//         int a, b;
//         cin >> s;
//         if(s == "C")
//         {
//             cin >> a >> b;
//             a = find(a), b = find(b);
//             if(a != b)
//             {
//                 p[a] = b;
//                 cnt[b] += cnt[a];
//             }
//         }
//         else if(s == "Q1")
//         {
//             cin >> a >> b;
//             if(find(a) == find(b))
//                 cout << "Yes" << endl;
//             else
//                 cout << "No" << endl;
//         }
//         else
//         {
//             cin >> a;
//             cout << cnt[find(a)] << endl;
//         }
//     }
    
//     return 0;
// }

#include <iostream>

using namespace std;

const int N = 50010;
int n, k, p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) 
    {p[i] = i, d[i] = 0;}

    int res = 0;
    while(k--)
    {
        int D, x, y;
        scanf("%d%d%d", &D, &x, &y);
        if(x > n || y > n) res++;
        else
        {
            int px = find(x), py = find(y);
            if(D == 1)
            {
                if(px == py && (d[x] - d[y]) % 3) res++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if(px == py && (d[x] - d[y] - 1) % 3) res++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }

    cout << res;

    return 0;
}


