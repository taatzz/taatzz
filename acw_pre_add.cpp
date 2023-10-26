#define _CRT_SECURE_NO_WARNINGS

// 一维前缀和
// #include <iostream>

// using namespace std;

// const int N = 100010;
// int n, m;
// int a[N], s[N];

// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++)
//         scanf("%d", &a[i]);
//     for(int i = 1; i <= n; i++)
//         s[i] = s[i-1] + a[i];
    
//     while(m--)
//     {
//         int l, r;
//         cin >> l >> r;
        
//         cout << s[r] - s[l-1] << endl;
//     }
    
//     return 0;
// }

// 二维前缀和
#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];

int main()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    
    while(q--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        
        cout << s[x2][y2] - s[x2][y1 -1] - s[x1 - 1][y2] + s[x1-1][y1-1] << endl;
    }
    
    return 0;
}