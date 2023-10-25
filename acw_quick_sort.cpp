#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

// 快速排序
const int N = 100010;
int n;
int arr[N];

// void quick_sort(int left, int right)
// {
//     int val = arr[(left + right) >> 1];
//     int l = left - 1, r = right + 1;

//     while(l < r)
//     {
//         do l++; while(arr[l] < val);
//         do r--; while(arr[r] > val);
//         if(l < r)
//             swap(arr[l], arr[r]);
//     }

//     quick_sort(left, r);
//     quick_sort(r + 1, right);

// }

// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     quick_sort(0, n - 1);

//     for(int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }

void merge_sort(int left, int right, int* tmp)
{
    if(left >= right)
        return;
    int mid = (left + right) >> 1;

    // 分解
    merge_sort(left, mid, tmp);
    merge_sort(mid + 1, right, tmp);

    // 归并
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int index = left;

    while(begin1 <= end1 && begin2 <= end2)
    {
        if(arr[begin1] < arr[begin2])
            tmp[index++] = arr[begin1++];
        else
            tmp[index++] = arr[begin2++];
    }

    while(begin1 <= end1)
        tmp[index++] = arr[begin1++];
    while(begin2 <= end2)
        tmp[index++] = arr[begin2++];
    
    for(int i = left; i <= right; i++)
        arr[i] = tmp[i];
}

int main()
{
    cin >> n;
    int tmp[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge_sort(0, n - 1, tmp);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}