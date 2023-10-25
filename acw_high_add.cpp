// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> add(vector<int>& a, vector<int>& b)
// {
//     vector<int> c;

//     if(a.size() < b.size())
//         return add(b, a);

//     int t = 0;
//     for(int i = 0; i < a.size(); i++)
//     {
//         t += a[i];
//         if(i < b.size())
//             t += b[i];
//         c.push_back(t % 10);
//         t /= 10;
//     }

//     if(t)   
//         c.push_back(1);
//     return c;
// }

// int main()
// {
//     string a, b;
//     cin >> a >> b;
//     vector<int> num1, num2;
//     for(int i = a.size() - 1; i >= 0; i--)
//         num1.push_back(a[i] - '0');
//     for(int i = b.size() - 1; i >= 0; i--)
//         num2.push_back(b[i] - '0');
    
//     auto c = add(num1, num2);
    
//     for(int i = c.size() - 1; i >= 0; i--)
//         cout << c[i];

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;
// // a >= b
// bool check(vector<int>& a, vector<int>& b)
// {
//     if(a.size() != b.size())
//         return a.size() > b.size();
//     else
//     {
//         for(int i = a.size() - 1; i >= 0; i--)
//             if(a[i] != b[i])
//                 return a[i] > b[i];
//     }

//     return true;
// }

// vector<int> sub(vector<int>& a, vector<int>& b)
// {

//     int t = 0; 
//     vector<int> c;
//     for(int i = 0; i < a.size(); i++)
//     {
//         t = a[i] - t;
//         if(i < b.size())
//             t -= b[i];
//         c.push_back((t + 10) % 10);

//         if(t < 0)
//             t = 1;
//         else t = 0;
//     }

//     while(c.size() > 1 && c.back() == 0)
//         c.pop_back();
//     return c;
// }

// int main()
// {
//     string a, b;
//     cin >> a >> b;
//     vector<int> A, B;
//     for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
//     for(int j = b.size() - 1; j >= 0; j--) B.push_back(b[j] - '0');

//     if(check(A, B))
//     {
//         auto c = sub(A, B);
//         for(int i = c.size() - 1; i >= 0; i--) cout << c[i];
//     }
//     else
//     {
//         cout << "-";
//         auto c = sub(B, A);
//         for(int i = c.size() - 1; i >= 0; i--) cout << c[i];
//     }
// }


// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// vector<int> mul(vector<int>& a, int b)
// {
//     int t = 0;
//     vector<int> c;

//     for(int i = 0; i < a.size() || t; i++)
//     {
//         if(i < a.size())
//             t += a[i] * b;
//         c.push_back(t % 10);
//         t /= 10;
//     }
    
//     while(c.size() > 1 && c.back() == 0) c.pop_back();
    
//     return c;
// }

// int main()
// {
//     string a; 
//     int b;
//     cin >> a >> b;
//     vector<int> A;
//     for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

//     auto c = mul(A, b);

//     for(int i = c.size() - 1; i >= 0; i--) cout << c[i];

//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int>& a, int b, int& r)
{
    r = 0;
    vector<int> c;

    // 最高位开始算
    for(int i = a.size() - 1; i >= 0; i--)
    {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    
    // 反转删除前导0，数组前端的删除不容易
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0) c.pop_back();

    return c;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    // 个位在前
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    int r;
    auto c = div(A, b, r);
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i];
    cout << endl << r;

    return 0;
}