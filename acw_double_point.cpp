// #include <iostream>

// using namespace std;

// const int N = 100010;
// int n, m, x;

// int a[N], b[N];

// int main()
// {
//     cin >> n >> m >> x;
//     for(int i = 0; i < n; i++)
//         cin >> a[i];
//     for(int i = 0; i < m; i++)
//         cin >> b[i];

//     int i = 0, j = m - 1;
//     for(int i = 0, j = m - 1; i < n; i++)
//     {
//         while(j >= 0 && a[i] + b[j] > x) j--;
//         if(j >= 0 && a[i] + b[j] == x)
//             cout << i << " " << j;
//     }

//     return 0;
// }


// #include <iostream>

// using namespace std;

// const int N = 100010;
// int n, m;
// int a[N], b[N];

// int main()
// {
//     cin >> n >> m;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     for(int i = 0; i < m; i++) cin >> b[i];

//     int i = 0, j = 0;
//     while(i < n && j < m)
//     {
//         if(a[i] == b[j])
//         {
//             i++;
//             j++;
//         }
//         else j++;
//     }
//     if(i >= n)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }


