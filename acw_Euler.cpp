// 朴素求欧拉函数
// #include <iostream>

// using namespace std;

// int n;

// int main()
// {
//     cin >> n;

//     while(n --)
//     {
//         int a;
//         cin >> a;
//         long long res = a;
//         for(int i = 2; i <= a / i; i++)
//         {
//             if(a % i == 0)
//             {
//                 res = res / i * (i - 1);
//                 while(a % i == 0)
//                 {
//                     a /= i;
//                 }
//             }
//         }
//         if(a > 1) res = res / a * (a - 1);

//         cout << res << endl;
//     }

//     return 0;
// }


// 线性筛法求欧拉函数
// #include <iostream>

// using namespace std;

// typedef long long LL;
// int n;
// const int N = 1000010;
// int primes[N], cnt;
// int euler[N];
// bool st[N];

// LL get_euler()
// {
//     euler[1] = 1;
//     for(int i = 2; i <= n; i++)
//     {
//         if(!st[i]) 
//         {
//             euler[i] = i - 1;
//             primes[cnt++] = i;
//         }
        
//         for(int j = 0; primes[j] <= n / i; j ++)
//         {
//             st[primes[j] * i] = 1;
//             if(i % primes[j] == 0) 
//             {
//                 euler[primes[j] * i] = euler[i] * primes[j];
//                 break;
//             }
//             euler[primes[j] * i] = euler[i] * (primes[j] - 1);
//         }
//     }

//     long long res = 0;
//     for(int i = 1; i <= n; i++) res += euler[i];
    
//     return res;
// }

// int main()
// {
//     cin >> n;
    
//     cout << get_euler() << endl;
    
    
//     return 0;
// }



// 快速幂
#include <iostream>

using namespace std;

int n;

long long qmi(int a, int b, int p)
{
    long long res = 1 % p;
    while(b)
    {
        if(b & 1) res = res * a % p;
        a = a * (long long)a % p;
        b >>= 1;
    }

    return res;
}
int main()
{
    cin >> n;
    
    while(n --)
    {
        int a, b, p;
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }

    return 0;
}