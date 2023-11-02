#include <iostream>

using namespace std;

const int N = 100010;
int n, m, a[N];

void down(int p, int size)
{
    int child = 2 * p + 1;
    while(child < size)
    {
        if(child + 1 < size && a[child + 1] < a[child]) child += 1;
        if(a[child] < a[p]) 
        {
            swap(a[child], a[p]);
            p = child;
            child = 2 * p + 1;
        }
        else break;
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = (n - 2) / 2; i >= 0; i--) down(i, n);

    int size = n;
    while(m -- )
    {
        cout << a[0] << " ";
        swap(a[0], a[size-1]);
        size--;
        down(0, size);
    }

    return 0;
}