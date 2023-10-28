#include <iostream>

using namespace std;

const int N = 100010;
int n, q;
int a[N];

int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    while(q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(a[mid] < x) r = mid;
            else l = mid + 1;
        }
        if(r >= n)
        {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        else
        {
            cout << r << " ";
            l = 0, r = n;
            while(l < r)
            {
                int mid = (l + r + 1) >> 1;
                if(a[mid] >= x) l = mid + 1;
                else r = mid;
            }
            cout << r << endl;
        }
    }
    return 0;
}
