// #include <iostream>

// using namespace std;

// const int N = 100010;
// int m, head = -1, index = 0;
// int val[N], ne[N];

// void add_head(int x)
// {
//     val[index] = x;
//     ne[index] = head;
//     head = index;
//     index++;
// }

// void remove(int k)
// {
//     ne[k] = ne[ne[k]];
// }

// void insert(int k, int x)
// {
//     val[index] = x;
//     ne[index] = ne[k];
//     ne[k] = index;
//     index++;
// }

// int main()
// {
//     cin >> m;
//     while(m--)
//     {
//         char c;
//         cin >> c;
//         if(c == 'H')
//         {
//             int x;
//             cin >> x;
//             add_head(x);
//         }
//         else if(c == 'D')
//         {
//             int k;
//             cin >> k;
//             if(k == 0) head = ne[head];
//             remove(k - 1);
//         }
//         else
//         {
//             int k, x;
//             cin >> k >> x;
//             insert(k - 1, x);
//         }
//     }
//     for(int i = head; i != -1; i = ne[i])
//         cout << val[i] << " ";
//     cout << endl;


//     return 0;
// }


#include <iostream>

using namespace std;

const int N = 100010;
int m, index = 2;
int val[N], pre[N], ne[N];

void init()
{
    ne[0] = 1;
    pre[1] = 0;
}

void insert(int k, int x)
{
    val[index] = x;
    ne[index] = ne[k];
    pre[index] = k;
    pre[ne[k]] = index;
    ne[k] = index;
    index++;
}

void remove(int k)
{
    pre[ne[k]] = pre[k];
    ne[pre[k]] = ne[k];
}

int main()
{
    cin >> m;
    init();
    while(m --) 
    {
        string c;
        cin >> c;
        if(c == "L")
        {
            int x;
            cin >> x;
            insert(0, x);
        }
        else if(c == "R")
        {
            int x;
            cin >> x;
            insert(pre[1], x);
        }
        else if(c == "D")
        {
            int k;
            cin >> k;
            remove(k + 1);
        }
        else if(c == "IL")
        {
            int k, x;
            cin >> k >> x;
            insert(pre[k + 1], x);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            insert(k + 1, x);
        }
    }
    for(int i = ne[0]; i != 1; i = ne[i]) cout << val[i] << " ";
    cout << endl;


    return 0;
}
