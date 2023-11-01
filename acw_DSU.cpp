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


#include <iostream>

using namespace std;

const int N = 100010;
int n, m;
int p[N], cnt[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    
    while (m -- )
    {
        string s;
        int a, b;
        cin >> s;
        if(s == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if(a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if(s == "Q1")
        {
            cin >> a >> b;
            if(find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    
    return 0;
}